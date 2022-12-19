#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

class SdlRenderer;
class SdlTexture;
class SdlText;

namespace SDL2pp
{
	class Color;
}

/**
 * @brief Color represents a red-green-blue color with alpha.
 */
class Color {
	friend class SdlTexture;
	friend class SdlRenderer;
	friend class SdlText;
private:
    /**
     * @brief Explicit constructor.
     * @param color SDL2pp::Color object of which the rgba values will be copied.
     */
	explicit Color(const SDL2pp::Color& color);

    /**
     * @brief Explicit operator which transforms a SDL2pp::Color object to a Color object.
     */
    explicit operator SDL2pp::Color() const;
public:
    /**
     * @brief Constructor, accepting an rgb value and an alpha (transparency).
     * @param r The red component, 0 ≤ r ≤ 1.
     * @param g The green component, 0 ≤ g ≤ 1.
     * @param b The blue component, 0 ≤ b ≤ 1.
     * @param a The transparency component, 0 ≤ alpha ≤ 1.
     * @spicapi
     */
	Color(unsigned int r = 0, unsigned int g = 0, unsigned int b = 0, unsigned int a = 0);

    /**
     * @brief Virtual destructor.
     */
	~Color() = default;

	unsigned int _r;
	unsigned int _g;
	unsigned int _b;
	unsigned int _a;

    /**
     * @brief Method which checks if two colors are the same.
     * @param other The Color object this will be compared to.
     * @returns Bool value if this Color object is the same as the other.
     */
	[[nodiscard]] bool equals(const Color &other) const;

    /**
     * @brief Method which checks if two colors are the same.
     * @param other The Color object this will be compared to.
     * @returns Bool value if this Color object is the same as the other.
     */
    [[nodiscard]] bool operator==(const Color &other) const;
};

#endif //ENGINE_COLOR_HPP
