#ifndef ENGINE_SDLTEXT_HPP
#define ENGINE_SDLTEXT_HPP

#include "render/itexture.hpp"
#include "color.hpp"

#include <memory>

class Text;

namespace SDL2pp {
	class Font;
	class Texture;
}

/**
 * @brief SDL text implementation of the ITexture interface.
 */
class SdlText : public ITexture
{
	friend class Text;
public:
	/**
	 * @brief Constructor.
	 * @param font_path (Relative) path to a font.
	 * @param font_size The size of the font.
	 * @param foreground_color The color of the foreground.
	 * @param background_color The color of the background.
	 */
	SdlText(const std::string& text,
		const std::string& font_path,
		const int font_size,
		const Color& foreground_color = Color{ 255, 255, 255, 0 },
		const Color& background_color = Color{ 0, 0, 0, 255 }
	);

    /**
     * @brief Virtual destructor.
     */
    virtual ~SdlText();

    /**
     * @brief Setter method for the color
     * @param color The Color object which will be set.
     */
	void set_color(const Color& color) override;
private:
	std::string _font_path;
	int _font_size;
	Color _foreground_color;
	Color _background_color;
	std::unique_ptr<SDL2pp::Font> _font;
	std::shared_ptr<SDL2pp::Texture> _texture;

    /**
     * @brief Cache method for the font.
     */
    void cache_font();

    /**
     * @brief Render method for the texture.
     * @param text The text string which will be rendered to the screen.
     */
	void render_texture(const std::string& text);

    /**
     * @brief Getter method for the texture.
     * @return A shared pointer to an SDL2pp::Texture object.
     */
    [[nodiscard]] std::shared_ptr<SDL2pp::Texture> get_texture() const override;

    /**
     * @brief Getter method for the x size.
     * @return A float value of the x size.
     */
	[[nodiscard]] float get_size_x() const override;

    /**
     * @brief Getter method for the y size.
     * @return A float value of the y size.
     */
    [[nodiscard]] float get_size_y() const override;
};

#endif // ENGINE_SDLTEXT_HPP