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

class SdlText : public ITexture
{
	friend class Text;
public:
	/**
	 * @brief A texture used by SDL, rendered from a font
	 * @param path (Relative) path to a font
	 */
	SdlText(const std::string& text,
		const std::string& font_path,
		const int font_size,
		const Color& foreground_color = Color{ 255, 255, 255, 0 },
		const Color& background_color = Color{ 0, 0, 0, 255 });

	/**
	 * @brief A texture used by SDL, rendered from a font
	 * @param path (Relative) path to a font
	 * @param[out] res_x X-axis resolution of the texture
	 * @param[out] res_y Y-axis resolution of the texture
	 */
	SdlText(const std::string& text,
		unsigned int* res_x,
		unsigned int* res_y,
		const std::string& font_path,
		const int font_size,
		const Color& foreground_color = Color{ 255, 255, 255, 0 },
		const Color& background_color = Color{ 0, 0, 0, 255 });

    virtual ~SdlText();

private:
	std::string _font_path;
	int _font_size;
	Color _foreground_color;
	Color _background_color;
	std::unique_ptr<SDL2pp::Font> _font;
	std::shared_ptr<SDL2pp::Texture> _texture;

	void cache_font();
	void render_texture(const std::string& text);
	void get_resolution(unsigned int* res_x, unsigned int* res_y) const;
	[[nodiscard]] std::shared_ptr<SDL2pp::Texture> get_texture() const override;
	[[nodiscard]] float get_size_x() const override;
	[[nodiscard]] float get_size_y() const override;
};

#endif // ENGINE_SDLTEXT_HPP