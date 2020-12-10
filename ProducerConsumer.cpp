// ProducerConsumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Consumer.h"
#include "Producer.h"
#include <thread>

int main()
{
    SyncBuffer buffer(10);

    Producer producer1(&buffer);
    Consumer consumer1(&buffer);
    Producer producer2(&buffer);
    Consumer consumer2(&buffer);

    std::thread producer1_thread(&Producer::Produce, &producer1);
    std::thread consumer1_thread(&Consumer::Consume, &consumer1);

    std::thread producer2_thread(&Producer::Produce, &producer2);
    std::thread consumer2_thread(&Consumer::Consume, &consumer2);
    
    producer1_thread.join();
    consumer1_thread.join();
    producer2_thread.join();
    consumer2_thread.join();

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
