#ifndef SDL_RENDERER_H_Hbcayj12iU
#define SDL_RENDERER_H_Hbcayj12iU

#include "render/irenderer.hpp"
#include "components/colliders/collider.hpp"

#include <memory>
#include <list>

class b2PolygonShape;
class b2ChainShape;
class RenderCall;

namespace SDL2pp 
{
	class SDLTTF;
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
	 * @param transform Transform of the to be renderer gameobject
	 * @param is_world_space Whether this sprite should be rendered in world space or screen space
	 */
	void render_sprite(const Sprite& sprite, ITexture& texture, Transform& transform,  bool is_world_space) const override;

	/**
	 * @brief Renders a collider
	 */
	void render_rigid_body(const RigidBody& rigid_body, Transform& transform, bool is_world_space) const override;


	/**
	 * @brief Renders a line from points in world space
	 * @param vectors Vector of points (Vector2d), to be  drawn as a line
	 * @param color Color of the to-be-drawn line
	 */
	void render_lines(std::vector<Vector2d>& vectors, const Color& color) const override;

	/**
	 * @brief Renders a text object
	 * @param text The text to be rendered
	 */
	void render_text(const Text& text) const override;

	/**
	 * @brief Clears the backbuffer and applies a default colour
	 */
	void clear(const Color& color) const override;

	/**
	 * @brief Presents the composed backbuffer
	 */
	void push_to_screen() override;

	/**
     * @brief Adds a render call to the renderqueue
     * @param render_call The render call
     */
    void add_render_call(RenderCall& render_call) override;
	/**
	 * @brief Returns the SDL_Renderer instance
	 * @return A pointer to the SDL_Renderer instance
	 */
	std::shared_ptr<SDL2pp::Renderer> get_renderer();
	/*
	* @brief Toggles the windowstate from fullscreen to windowed;	
	*/
	void toggle_fullscreen() override;
	/*
	* @brief 
	*/
	void get_display_resolution(int* width, int* height);

	explicit SdlRenderer(int res_x = 800, int res_y = 600, bool fullscreen = true);
	virtual ~SdlRenderer();
private:
	void init(bool fullscreen);
	[[nodiscard]] SDL2pp::Point world_to_screen(const Vector2d& position) const;
	void render_ngon(b2Body* body, b2PolygonShape* shape) const;
	void render_ngon(b2Body* body, b2ChainShape* shape) const;

	std::unique_ptr<SDL2pp::SDL> _sdl;
	std::unique_ptr<SDL2pp::SDLImage> _sdl_image;
	std::unique_ptr<SDL2pp::SDLTTF> _sdl_ttf;
	std::shared_ptr<SDL2pp::Window> _window;
	std::shared_ptr<SDL2pp::Renderer> _renderer;
    std::list<RenderCall> _render_queue;

	// Todo move to something which gamedev can set
	float _mtp = 6.f;
	bool _fullscreen = false;
	int _windowed_res_x;
	int _windowed_res_y;
};

#endif // SDL_RENDERER_H_Hbcayj12iU