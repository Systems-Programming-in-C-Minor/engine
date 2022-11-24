#include "debug.hpp"

#include <iostream>

void Debug::log(const std::string &message)
{
    std::cout << "INFO - " << &message << std::endl;
}

void Debug::log_warning(const std::string &warning)
{
    std::cerr << "WARNING - " << &warning << std::endl;
}

void Debug::log_error(const std::string &error)
{
    std::cerr << "ERROR - " << &error << std::endl;
}

void Debug::draw_line(const Vector2d &start, const Vector2d &end, const Color &color)
{
    //TODO: https://app.clickup.com/t/377qjj4
}
