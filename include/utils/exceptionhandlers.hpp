#ifndef UTILS_EXCEPTIONHANDLERS_H_LeKQA1sZVJ
#define UTILS_EXCEPTIONHANDLERS_H_LeKQA1sZVJ

#include "SDL2pp/Exception.hh"
#include "fmt/ostream.h"

#include <iostream>

inline static void handle_fatal_exception(const SDL2pp::Exception& e)
{
	fmt::print(std::cerr, "SDL error in: {}\n", e.GetSDLFunction());
	fmt::print(std::cerr, "SDL error: {}\n", e.GetSDLError());
}

#endif // UTILS_EXCEPTIONHANDLERS_H_LeKQA1sZVJ