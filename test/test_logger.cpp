#include <atomic>
#include <cstdlib>
// #include <iostream>
#include <simple-logger/logger.hpp>

simple_logger::Logger logger;

std::atomic_int num;

void push(int index)
{
for(int i = 0; i < 20000;i++)
{
    logger.log("The value of number is",num++);
    // std::cout<<"wow"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
}

int main()
{
logger.initilze();

std::thread t2(&push,1);
std::thread t3(&push,2);
std::thread t4(&push,3);


if(t2.joinable())
   t2.join();

if(t3.joinable())
   t3.join();

if(t3.joinable())
   t3.join();

return 0;
}