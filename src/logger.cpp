#include <simple-logger/logger.hpp>

#include <string>
#include <iostream>

namespace simple_logger {

Logger::Logger(std::string name):
name_(name)
{ }

Logger::Logger(){}

void Logger::processMessage()
{
while(flag_)
{
auto msg = queue_.pop();
std::cout<<msg<<std::endl;
flag_ = queue_.empty();

}
}

template <typename... Args>
void Logger::log(Args... args)
{

}
}