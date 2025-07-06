#ifndef SIMPLE_LOGGER_TIMESTAMP_HPP_
#define SIMPLE_LOGGER_TIMESTAMP_HPP_

#include <chrono>
#include <ctime>

#include <cstdint>

namespace simple_logger {
struct TimeStamp
{
public:
TimeStamp()
{
auto now = std::chrono::system_clock::now();

std::time_t current_time = std::chrono::system_clock::to_time_t(now);

std::tm* local_time = std::localtime(&current_time);

year_ = local_time->tm_year + 1900; 
month_ = local_time->tm_mon + 1; 
day_ = local_time->tm_mday;
hour_ = local_time->tm_hour;
minute_ = local_time->tm_min;
second_ = local_time->tm_sec;
}

TimeStamp(TimeStamp& ) = delete;

TimeStamp& operator=(TimeStamp& ) = delete;

int get_year(){ return year_; }

int get_month(){ return month_; }

int get_day(){ return day_; }

int get_hour(){ return hour_; }

int get_minute(){ return minute_; }

float get_second(){ return second_; }

private:
uint16_t year_;
int month_;
int day_;
int hour_;
int minute_;
float second_;
};
}
#endif