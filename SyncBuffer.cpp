#include "SyncBuffer.h"
#include <iostream>

void SyncBuffer::AddData(int data)
{
	std::unique_lock<std::mutex> locker(m_mutex);
	auto isFull = [this]() { return IsBufferSpaceAvailable(); };
	m_cv.wait(locker, isFull);
	m_DataList.push_back(data);
	std::cout << std::this_thread::get_id() << "Data added : " << data << std::endl;
	locker.unlock();
	m_cv.notify_all();
}

int SyncBuffer::getData()
{
	std::unique_lock<std::mutex> locker(m_mutex);
	auto isEmpty = [this]() { return IsBufferEmpty (); };
	m_cv.wait(locker, isEmpty);
	int data = *(m_DataList.rbegin());
	m_DataList.pop_back();
	locker.unlock();
	m_cv.notify_all();
	return data;
}

bool SyncBuffer::IsBufferSpaceAvailable()
{
	return m_DataList.size() < m_Size;
}

bool SyncBuffer::IsBufferEmpty()
{
	return m_DataList.size() > 0;
}
