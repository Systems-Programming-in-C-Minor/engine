#ifndef ENGINE_MOCK_RENDERER_HPP
#define ENGINE_MOCK_RENDERER_HPP

#include <gmock/gmock.h>
#include <render/irenderer.hpp>

#include <vector>

class Vector2d;
class Color;

class MockRenderer : public IRenderer {
public:
	MOCK_METHOD(std::shared_ptr<TexturePool>, get_texture_pool, (), (const, override));
	MOCK_METHOD(Vector2d, screen_to_world_space, (const Vector2d&), (const, override));
	MOCK_METHOD(void, render_texture, (ITexture&, Transform&, float), (const, override));
	MOCK_METHOD(void, render_texture, (ITexture&, Transform&, float, float), (const, override));
	MOCK_METHOD(void, render_rigid_body, (const RigidBody&), (const, override));
	MOCK_METHOD(Vector2d, transform_vector, (const Vector2d&), (const, override));
	MOCK_METHOD(Vector2d, world_space_to_screen, (const Vector2d&), (const, override));
	MOCK_METHOD(Vector2d, screen_space_to_screen, (const Vector2d&), (const, override));
	MOCK_METHOD(Vector2d, screen_to_screen_space, (const Vector2d&), (const, override));
	MOCK_METHOD(void, render_lines, (const std::vector<Vector2d>&, const Color&), (const, override));
	MOCK_METHOD(void, add_render_call, (RenderCall&), (override));
	MOCK_METHOD(void, clear, (), (const, override));
	MOCK_METHOD(void, push_to_screen, (), (override));
	MOCK_METHOD(void, toggle_fullscreen, (), (override));
	MOCK_METHOD(void, toggle_debug_mode, (), (override));
};

#endif //ENGINE_MOCK_RENDERER_HPP
