#include "Consumer.h"
#include <iostream>

void Consumer::Consume()
{
	int num = 0;

	do
	{
		num = m_Buffer->getData();

		std::lock_guard <std::mutex> lg(print_mutex);
		std::cout << std::this_thread::get_id () <<"Consumed : " << num << std::endl;
		//print_mutex.unlock();
	} while (num != 10);
}
