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

class IRenderer {
public:
	virtual void render_sprite(const Sprite &sprite, ITexture &texture, Transform& transform, bool is_world_space) const = 0;
	virtual void render_texture(ITexture & texture, Transform & transform, bool is_world_space, float pixels_to_meters) const = 0;
    virtual void render_texture(ITexture & texture, Transform & transform, bool is_world_space,  float width, float height) const = 0;
	virtual void render_rigid_body(const RigidBody& rigid_body, Transform& transform, bool is_world_space) const = 0;
	virtual void render_lines(std::vector<Vector2d>& vectors, const Color& color) const = 0;
	virtual void clear(const Color& color) const = 0;
	virtual void push_to_screen() = 0;
    virtual void add_render_call(RenderCall& render_call) = 0;
	virtual void toggle_fullscreen() = 0;
	virtual void toggle_debug_mode() = 0;
	[[nodiscard]] virtual Vector2d transform_vector(const Vector2d &position) const = 0;
	[[nodiscard]] virtual Vector2d world_space_to_screen(const Vector2d& position) const = 0;
	[[nodiscard]] virtual Vector2d screen_space_to_screen(const Vector2d & position) const = 0;
	[[nodiscard]] virtual Vector2d screen_to_screen_space(const Vector2d & position) const = 0;

    virtual ~IRenderer() = default;
};

#endif //ENGINE_IRENDERER_HPP
