#ifndef SDL_RENDERER_H_Hbcayj12iU
#define SDL_RENDERER_H_Hbcayj12iU

#include "render/irenderer.hpp"

#include <memory>

namespace SDL2pp 
{
	class SDLImage;
	class SDL;
	class Window;
	class Renderer;
	class Exception;
	class Point;
}

class Sprite;
class ITexture;
class Text;
class Color;
class Transform;
class Vector2d;

class SdlRenderer : public IRenderer {
public:

	/**
	 * @brief Renders a sprite
	 * @param sprite Sprite to be rendered
	 * @param texture Texture to be rendered, belonging to the same sprite
	 * @param is_world_space Whether this sprite should be rendered in world space or screen space
	 */
	void render_sprite(const Sprite& sprite, ITexture& texture, Transform& transform,  bool is_world_space) const override;

	/**
	 * @brief Renders a collider
	 */
	void render_collider() const override;

	/**
	 * @brief Renders a text object
	 * @param text The text to be rendered
	 */
	void render_text(Text& text) const override;

	/**
	 * @brief Clears the backbuffer and applies a default colour
	 */
	void clear(const Color& color) const override;

	/**
	 * @brief Presents the composed backbuffer
	 */
	void push_to_screen() const override;


	/**
	 * @brief Returns the SDL_Renderer instance
	 * @return A pointer to the SDL_Renderer instance
	 */
	std::shared_ptr<SDL2pp::Renderer> get_renderer();

	explicit SdlRenderer(int res_x = 800, int res_y = 600);
	virtual ~SdlRenderer();
private:
	void init(int res_x = 800, int res_y = 600);
	[[nodiscard]] SDL2pp::Point world_to_screen(const Vector2d& position) const;

	std::unique_ptr<SDL2pp::SDL> _sdl;
	std::unique_ptr<SDL2pp::SDLImage> _sdl_image;
	std::shared_ptr<SDL2pp::Window> _window;
	std::shared_ptr<SDL2pp::Renderer> _renderer;

	// Todo move to something which gamedev can set
	double _mtp = 100.0;
};

#endif // SDL_RENDERER_H_Hbcayj12iU