#ifndef SIMPLE_LOGGER_LOGGER_HPP_
#define SIMPLE_LOGGER_LOGGER_HPP_

// #include <iostream>
#include <atomic>
#include <chrono>
#include <thread>

#include "message_queue.hpp"

namespace simple_logger{
// 线程安全
class Logger
{
public:
Logger(std::string name);

Logger();

// 接收参数包
template <typename... Args>
void log(Args... args);

void processMessage();

private:

std::thread printf_thread_;

// 
std::atomic<bool> flag_;

// 日志名字
std::string name_;

// 消息队列
MessageQueue<std::string> queue_;
};
}

#endif