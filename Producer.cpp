#include "Producer.h"

void Producer::Produce()
{
	int num = 0;
	do
	{
		num = rand() / 100;
		m_Buffer->AddData(num);
	} while (num != 10);
}
