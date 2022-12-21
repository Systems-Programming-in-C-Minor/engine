#ifndef SDL_RENDERER_H_Hbcayj12iU
#define SDL_RENDERER_H_Hbcayj12iU

#include "render/irenderer.hpp"
#include "components/colliders/collider.hpp"
#include "render/texture_pool.hpp"

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

/**
 * @brief SDL renderer implementation of the IRenderer interface.
 */
class SdlRenderer : public IRenderer {
public:

    /**
     * @brief Renders a texture
     * @param texture The texture which will be rendered.
     * @param transform The transform where the texture will be rendered.
     * @param pixels_to_meters The pixels to meters ratio which will be used.
     */
	void render_texture(ITexture & texture, Transform & transform, float pixels_to_meters) const override;

    /**
     * @brief Renders a texture
     * @param texture The texture which will be rendered.
     * @param transform The transform where the texture will be rendered.
     * @param width The width of the rendered texture.
     * @param height The height of the rendered texture.
     */
    void render_texture(ITexture & texture, Transform & transform, float width, float height) const override;

	/**
	 * @brief Renders a collider.
	 * @param rigid_body The rigid body of the collider.
	 */
	void render_rigid_body(const RigidBody& rigid_body) const override;

	/**
	 * @brief Renders a line from points in world space
	 * @param vectors Vector of points (Vector2d), to be  drawn as a line
	 * @param color Color of the to-be-drawn line
	 */
	void render_lines(const std::vector<Vector2d>& vectors, const Color& color) const override;

	/**
	 * @brief Clears the back buffer and applies a default colour
	 */
	void clear() const override;

	/**
	 * @brief Presents the composed back buffer
	 */
	void push_to_screen() override;

	/**
     * @brief Adds a render call to the render queue
     * @param render_call The render call
     */
    void add_render_call(RenderCall& render_call) override;

	/**
	 * @brief Returns the SDL_Renderer instance
	 * @return A pointer to the SDL_Renderer instance
	 */
	std::shared_ptr<SDL2pp::Renderer> get_renderer();

	/**
	* @brief Toggles the windowstate from fullscreen to windowed	
	*/
	void toggle_fullscreen() override;

	/**
	* @brief Toggles the debug mode on/off
	*/
	void toggle_debug_mode() override;

    /**
    * @brief Explicit Constructor.
    * @param res_x The resolution of the x axis.
    * @param res_y The resolution of the y axis.
    * @param fullscreen Boolean value whether or not fullscreen is enabled.
    * @param debug_mode Boolean value whether or not debug mode is enabled.
    */
    explicit SdlRenderer(int res_x = 800, int res_y = 600, bool fullscreen = false, bool debug_mode = false);

    /**
    * @brief Virtual destructor.
    */
	virtual ~SdlRenderer();

private:
    /**
    * @brief Initializer method of the renderer.
    * @param fullscreen Whether or not the renderer will be initialized in fullscreen.
    */
    void init(bool fullscreen);

    /**
     * @brief Method which transforms a vector to the correct camera position, using the given vector2d.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] Vector2d transform_vector(const Vector2d &position) const override;

    /**
     * @brief Method which translates world space to the screen, using the given vector2d.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] Vector2d world_space_to_screen(const Vector2d& position) const override;

    /**
     * @brief Method which translates screen space to the screen, using the given vector2d.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] Vector2d screen_space_to_screen(const Vector2d & position) const override;

    /**
     * @brief Method which translates the screen to screen space, using the given vector2d.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] Vector2d screen_to_screen_space(const Vector2d & position) const override;

    /**
     * @brief Method which translates the screen to world space, using the given vector2d.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
    [[nodiscard]] Vector2d screen_to_world_space(const Vector2d & position) const;

    /**
     * @brief Method which renders an ngon.
     * @param body The b2Body which will be used.
     * @param shape The b2PolygonShape which will be rendered.
     * */
	void render_ngon(b2Body* body, b2PolygonShape* shape) const;

    /**
     * @brief Method which renders an ngon.
     * @param body The b2Body which will be used.
     * @param shape The b2ChainShape which will be rendered.
     * */
    void render_ngon(b2Body* body, b2ChainShape* shape) const;

    [[nodiscard]] std::shared_ptr<TexturePool> get_texture_pool() const override;


    std::unique_ptr<SDL2pp::SDL> _sdl;
	std::unique_ptr<SDL2pp::SDLImage> _sdl_image;
	std::unique_ptr<SDL2pp::SDLTTF> _sdl_ttf;
	std::shared_ptr<SDL2pp::Window> _window;
	std::shared_ptr<SDL2pp::Renderer> _renderer;
    std::list<RenderCall> _render_queue;
    std::shared_ptr<TexturePool> _texture_pool;

	// Todo move to something which gamedev can set
	float _mtp = 6.f;
	bool _fullscreen = false;
	int _windowed_res_x;
	int _windowed_res_y;
	bool _debug_mode = false;
};

#endif // SDL_RENDERER_H_Hbcayj12iU