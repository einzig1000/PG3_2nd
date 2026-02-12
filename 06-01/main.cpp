#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current = 1;

void print_thread(int id)
{
    std::cout << "thread " << id << std::endl;
}

int main()
{
    std::thread t1(print_thread, 1);
    t1.join();
    std::thread t2(print_thread, 2);
    t2.join();
    std::thread t3(print_thread, 3);
    t3.join();


    return 0;
}