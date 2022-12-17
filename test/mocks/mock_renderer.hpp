#ifndef ENGINE_MOCK_RENDERER_HPP
#define ENGINE_MOCK_RENDERER_HPP

#include <gmock/gmock.h>
#include <render/irenderer.hpp>

#include <vector>

class Vector2d;
class Color;

class MockRenderer : public IRenderer {
public:
	MOCK_METHOD(void, render_lines, (std::vector<Vector2d>&, const Color&), (const, override));
	MOCK_METHOD(void, render_rigid_body, (const RigidBody&, Transform&, bool), (const, override));
	MOCK_METHOD(void, add_render_call, (RenderCall&), (override));
	MOCK_METHOD(void, render_text, (const Text&), (const, override));
	MOCK_METHOD(void, clear, (const Color&), (const, override));
	MOCK_METHOD(void, push_to_screen, (), (override));
	MOCK_METHOD(void, render_sprite, (const Sprite &, ITexture &, Transform &, bool), (override, const));
	MOCK_METHOD(void, toggle_fullscreen, (), (override));
	MOCK_METHOD(void, toggle_debug_mode, (), (override));
};

#endif //ENGINE_MOCK_RENDERER_HPP
