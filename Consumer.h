#pragma once
#include "SyncBuffer.h"
class Consumer
{
public:
	Consumer(SyncBuffer* buffer)
	{
		m_Buffer = buffer;
	}
	void Consume();
	
private:
	SyncBuffer* m_Buffer;
	std::mutex print_mutex;
};

