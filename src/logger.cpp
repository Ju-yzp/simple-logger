#include <simple-logger/logger.hpp>

#include <iostream>

namespace simple_logger {

Logger::Logger(std::string name,LoggerOption &option):
name_(name),option_(option)
{ }

Logger::Logger(){
if(printf_thread_.joinable())
   printf_thread_.join();
}

void Logger::processMessage()
{
while(true)
{
while(!queue_.empty())
{
std::string msg = queue_.pop();

std::cout<<msg<<std::endl;

}
std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
}

void Logger::initilze()
{
printf_thread_ = std::thread(&Logger::processMessage,this);
}
}