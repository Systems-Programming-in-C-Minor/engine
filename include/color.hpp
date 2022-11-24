#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

#include <cstdint>

class SDL_Color;

class Color {
public:
    Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 0);
    ~Color() = default;

    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
    uint8_t _a;

    [[nodiscard]] SDL_Color get_color() const;

[[nodiscard]] bool equals(const Color &other) const;
[[nodiscard]] bool operator==(const Color &other) const;
};

#endif //ENGINE_COLOR_HPP
