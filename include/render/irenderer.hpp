#ifndef ENGINE_IRENDERER_HPP
#define ENGINE_IRENDERER_HPP
#include <vector>

class Sprite;
class Text;
class Color;
class ITexture;
class Transform;
class RenderCall;
class RigidBody;
class Vector2d;

/**
 * @brief Interface for all renderers.
 */
class IRenderer {
public:
    /**
     * @brief Render a sprite to the screen.
     *        Override for implementing the desired behaviour.
     * @param sprite The sprite which will be rendered to the screen.
     * @param texture The source texture.
     * @param transform The transform where the sprite will be rendered.
     * @param is_world_space Optionally render in world space.
     * */
	virtual void render_sprite(const Sprite &sprite, ITexture &texture, Transform& transform, bool is_world_space) const = 0;

    /**
     * @brief Render a rigid body to the screen.
     *        Override for implementing the desired behaviour.
     * @param rigid_body The rigid body which will be rendered to the screen.
     * @param is_world_space Optionally render in world space.
     * */
    virtual void render_rigid_body(const RigidBody& rigid_body, Transform& transform, bool is_world_space) const = 0;

    /**
     * @brief Render lines to the screen.
     *        Override for implementing the desired behaviour.
     * @param vectors The vectors on which the line will be rendered.
     * @param color The desired color of the line.
     * */
	virtual void render_lines(std::vector<Vector2d>& vectors, const Color& color) const = 0;

    /**
     * @brief Render text to the screen.
     *        Override for implementing the desired behaviour.
     * @param text The text object which will be rendered to the screen.
     * */
    virtual void render_text(const Text& text) const = 0;

    /**
     * @brief Clear the screen of all known objects in the render queue.
     *        Override for implementing the desired behaviour.
     * */
	virtual void clear(const Color& color) const = 0;

    /**
     * @brief Method which pushes all known objects in the render queue to the screen.
     *        Override for implementing the desired behaviour.
     * */
    virtual void push_to_screen() = 0;

    /**
     * @brief Add a render call to the render queue.
     *        Override for implementing the desired behaviour.
     * @param render_call The RenderCall which will be added to the queue.
     * */
    virtual void add_render_call(RenderCall& render_call) = 0;

    /**
     * @brief Method which toggles fullscreen.
     *        Override for implementing the desired behaviour.
     * */
    virtual void toggle_fullscreen() = 0;

    /**
     * @brief Method which toggles debug mode.
     *        Override for implementing the desired behaviour.
     * */
	virtual void toggle_debug_mode() = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IRenderer() = default;
};

#endif //ENGINE_IRENDERER_HPP
