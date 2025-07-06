#include <chrono>
#include <iostream>
#include <thread>
#include <iomanip>

#include <simple-logger/timestamp.hpp>

int main()
{
for(int count = 0; count < 100; count++)
{
simple_logger::TimeStamp timestamp;

std::cout << timestamp.get_year() << "-"
            << std::setw(2) << std::setfill('0') << timestamp.get_month() << "-"
            << std::setw(2) << std::setfill('0') << timestamp.get_day() << " "
            << std::setw(2) << std::setfill('0') << timestamp.get_hour() << ":"
            << std::setw(2) << std::setfill('0') << timestamp.get_minute() << ":"
            << std::setw(2) << std::setfill('0') << timestamp.get_second()
            << std::endl;

std::this_thread::sleep_for(std::chrono::seconds(5));
}
}