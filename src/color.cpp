#include "color.hpp"
#include "SDL2pp/Color.hh"

Color::Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a): _r(r), _g(g), _b(b), _a(a){}

Color::Color(const SDL2pp::Color& color): _r(color.r), _g(color.g), _b(color.b), _a(color.a){}

bool Color::equals(const Color& other) const {
	return _r == other._r && _g == other._g && _b == other._b && _a == other._a;
}

bool Color::operator==(const Color& other) const {
	return _r == other._r && _g == other._g && _b == other._b && _a == other._a;
}

Color::operator SDL2pp::Color() const {
	return SDL2pp::Color {
		static_cast<Uint8>(_r),
		static_cast<Uint8>(_g),
		static_cast<Uint8>(_b),
		static_cast<Uint8>(_a)
	};
}
