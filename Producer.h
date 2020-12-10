#pragma once
#include"SyncBuffer.h"

class Producer
{
public:
	Producer(SyncBuffer* buffer)
	{
		m_Buffer = buffer;
	}

	void Produce();
private:
	SyncBuffer* m_Buffer;
};

