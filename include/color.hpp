#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

namespace SDL2pp
{
    class Color;
}

class Color {
public:
    Color(unsigned int r = 0, unsigned int g = 0, unsigned int b = 0, unsigned int a = 0);
    explicit Color(const SDL2pp::Color& color);
    ~Color() = default;

    unsigned int _r;
    unsigned int _g;
    unsigned int _b;
    unsigned int _a;

[[nodiscard]] bool equals(const Color &other) const;
[[nodiscard]] bool operator==(const Color &other) const;
explicit operator SDL2pp::Color() const;
};

#endif //ENGINE_COLOR_HPP
