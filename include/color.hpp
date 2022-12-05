#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

class SdlRenderer;

namespace SDL2pp
{
	class Color;
}

class Color {
private:
	friend class SdlRenderer;
	explicit Color(const SDL2pp::Color& color);
	explicit operator SDL2pp::Color() const;
public:
	Color(unsigned int r = 0, unsigned int g = 0, unsigned int b = 0, unsigned int a = 0);
	~Color() = default;

	unsigned int _r;
	unsigned int _g;
	unsigned int _b;
	unsigned int _a;

	[[nodiscard]] bool equals(const Color &other) const;
	[[nodiscard]] bool operator==(const Color &other) const;
};

#endif //ENGINE_COLOR_HPP
