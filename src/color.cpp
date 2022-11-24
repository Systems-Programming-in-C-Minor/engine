#include "color.hpp"
#include "SDL2pp/Color.hh"

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a): _r(r), _g(g), _b(b), _a(a){}

bool Color::equals(const Color& other) const {
    return _r == other._r && _g == other._g && _b == other._b && _a == other._a;
}

bool Color::operator==(const Color& other) const {
    return _r == other._r && _g == other._g && _b == other._b && _a == other._a;
}

SDL_Color Color::get_color() const {
    return SDL_Color {_r, _g, _b, _a};
}
