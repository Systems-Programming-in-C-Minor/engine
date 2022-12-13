#ifndef ENGINE_MOCK_RENDERER_HPP
#define ENGINE_MOCK_RENDERER_HPP

#include <gmock/gmock.h>
#include <render/irenderer.hpp>

class MockRenderer : public IRenderer {
public:
	MOCK_METHOD(void, render_collider, (), (const, override));
	MOCK_METHOD(void, render_text, (const Text&), (const, override));
	MOCK_METHOD(void, clear, (const Color&), (const, override));
	MOCK_METHOD(void, push_to_screen, (), (const, override));
	MOCK_METHOD(void, render_sprite, (const Sprite &, ITexture &, Transform &, bool), (override, const));
};

#endif //ENGINE_MOCK_RENDERER_HPP
