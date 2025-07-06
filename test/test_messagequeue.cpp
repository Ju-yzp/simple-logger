#include <atomic>
#include <simple-logger/message_queue.hpp>

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

simple_logger::MessageQueue<std::string> msg_queue;

std::atomic<int> num;
void push(int index)
{
for(int i = 0; i < 20000;i++)
{
    msg_queue.push_back(std::string("Hello kitty"+std::to_string(index) + std::to_string(++num)));
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
}
}

void prinf_msg()
{
while(true)
{
while(!msg_queue.empty())
{
std::string msg = msg_queue.pop();

std::cout<<msg<<std::endl;

}
std::this_thread::sleep_for(std::chrono::milliseconds(5));
}
}

int main()
{
std::thread t1(&prinf_msg);
std::thread t2(&push,1);
std::thread t3(&push,2);
std::thread t4(&push,3);

if(t1.joinable())
   t1.join();

if(t2.joinable())
   t2.join();

if(t3.joinable())
   t3.join();

if(t3.joinable())
   t3.join();

return 0;
}