#ifndef SIMPLE_LOGGER_MESSAGE_QUEUE_HPP_
#define SIMPLE_LOGGER_MESSAGE_QUEUE_HPP_

#include <mutex>
#include <queue>


namespace  simple_logger{

template <typename T>
class MessageQueue
{
public:
void push_back(T &&msg)
{
std::scoped_lock<std::mutex> m(m_mutex_);
msg_queue_.push(msg);
}

T pop()
{
std::scoped_lock<std::mutex> m(m_mutex_);
T msg = msg_queue_.front();
msg_queue_.pop();
return msg;
}

bool empty()
{
std::scoped_lock<std::mutex> m(m_mutex_);
return msg_queue_.empty();  
}
private:
// 队列
std::queue<T> msg_queue_;

// 锁资源
std::mutex m_mutex_;
};

}
#endif