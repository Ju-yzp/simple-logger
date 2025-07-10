#ifndef SIMPLE_LOGGER_LOGGER_HPP_
#define SIMPLE_LOGGER_LOGGER_HPP_

// #include <iostream>
#include <thread>

#include <sstream>
#include <string>

#include <simple-logger/message_queue.hpp>
#include <simple-logger/logger_option.hpp>

namespace simple_logger{
// 线程安全
class Logger
{
public:
Logger(std::string name,LoggerOption &option);

Logger();

// 接收参数包
template <typename... Args>
std::string receive_msg(Args... args)
{
std::ostringstream oss;
return oss.str() + std::to_string(args...);
}

template <typename... Args>
void log(Args... args)
{
std::string msg = "1";
queue_.push_back(std::move(msg));
}

void processMessage();

void initilze();

private:

std::thread printf_thread_;

// 日志名字
std::string name_;

LoggerOption option_;

// 消息队列
MessageQueue<std::string> queue_;
};
}

#endif