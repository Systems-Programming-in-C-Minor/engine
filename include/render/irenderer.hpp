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
     * @brief Render a texture to the screen.
     *        Override for implementing the desired behaviour.
     * @param texture The source texture which will be rendered.
     * @param transform The transform where the texture will be rendered.
     * @param pixels_to_meters The pixel to meters ratio which will be used.
     * */
    virtual void render_texture(ITexture & texture, Transform & transform, float pixels_to_meters) const = 0;

    /**
     * @brief Render a texture to the screen.
     *        Override for implementing the desired behaviour.
     * @param texture The source texture which will be rendered.
     * @param transform The transform where the texture will be rendered.
     * @param width The width which will be used.
     * @param height The height which will be used.
     * */
    virtual void render_texture(ITexture & texture, Transform & transform, float width, float height) const = 0;

    /**
     * @brief Render a rigid body to the screen.
     *        Override for implementing the desired behaviour.
     * @param rigid_body The rigid body which will be rendered to the screen.
     * */
    virtual void render_rigid_body(const RigidBody& rigid_body) const = 0;
    
    /**
     * @brief Render lines to the screen.
     *        Override for implementing the desired behaviour.
     * @param vectors The vectors on which the line will be rendered.
     * @param color The desired color of the line.
     * */
	virtual void render_lines(const std::vector<Vector2d>& vectors, const Color& color) const = 0;
  
     /**
     * @brief Clear the screen of all known objects in the render queue.
     *        Override for implementing the desired behaviour.
     * */
    virtual void clear() const = 0;

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
     * @brief Method which transforms a vector to the correct camera position, using the given vector2d.
     *        Override for implementing the desired behaviour.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] virtual Vector2d transform_vector(const Vector2d &position) const = 0;

    /**
     * @brief Method which translates world space to the screen, using the given vector2d.
     *        Override for implementing the desired behaviour.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] virtual Vector2d world_space_to_screen(const Vector2d& position) const = 0;

    /**
     * @brief Method which translates screen space to the screen, using the given vector2d.
     *        Override for implementing the desired behaviour.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] virtual Vector2d screen_space_to_screen(const Vector2d & position) const = 0;

    /**
     * @brief Method which translates the screen to screen space, using the given vector2d.
     *        Override for implementing the desired behaviour.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] virtual Vector2d screen_to_screen_space(const Vector2d & position) const = 0;

    /**
     * @brief Method which translates the screen to world space, using the given vector2d.
     *        Override for implementing the desired behaviour.
     * @param position The vector2d used for transforming the vector.
     * @returns A transformed vector2d object.
     * */
	[[nodiscard]] virtual Vector2d screen_to_world_space(const Vector2d & position) const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IRenderer() = default;
};

#endif //ENGINE_IRENDERER_HPP
