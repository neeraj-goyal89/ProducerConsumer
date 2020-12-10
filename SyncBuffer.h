#pragma once
#include <vector>
#include <mutex>
#include <condition_variable>

class SyncBuffer
{
public:
	SyncBuffer() : m_Size(10) {}
	SyncBuffer (int _size) : m_Size (_size)
	{}

	void AddData(int data);
	int getData();
	bool IsBufferSpaceAvailable();
	bool IsBufferEmpty();

private:
	std::vector<int> m_DataList;
	std::size_t m_Size;
	std::mutex m_mutex;
	std::condition_variable m_cv;
};

