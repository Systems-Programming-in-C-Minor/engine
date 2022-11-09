#include "Engine.hpp"
#include <fmt/core.h>

std::string hello() {
    return fmt::format("{}, {}!", "Hello", "World");
}
