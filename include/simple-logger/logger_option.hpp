#ifndef SIMPLE_LOGGER_LOGGER_OPTION_HPP_
#define SIMPLE_LOGGER_LOGGER_OPTION_HPP_

namespace simple_logger {
class LoggerOption
{
public:
LoggerOption(){}

LoggerOption(bool is_printf_detailed_date)
:is_printf_detailed_date_(is_printf_detailed_date)
{}

void set_printf_detailed_date(bool flag = false){ is_printf_detailed_date_ = flag;}

bool get_printf_detailed_date(bool flag = false){ return is_printf_detailed_date_;}

private:
bool is_printf_detailed_date_;
};
}

#endif