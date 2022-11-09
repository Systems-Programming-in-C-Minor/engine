#include "Engine.hpp"
#include <fmt/core.h>

std::string hello() {
    auto x = new std::string();

    return fmt::format("{}, {}!", "Hello", "World") + *x;
}
