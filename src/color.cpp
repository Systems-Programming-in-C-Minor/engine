#include "color.hpp"

Color::Color(int r, int g, int b, int a): _r(r), _g(g), _b(b), _a(a){}

bool Color::equals(const Color& other) const {
    return _r == other._r && _g == other._g && _b == other._b && _a == other._a;
}

bool Color::operator==(const Color& other) const {
    return _r == other._r && _g == other._g && _b == other._b && _a == other._a;
}