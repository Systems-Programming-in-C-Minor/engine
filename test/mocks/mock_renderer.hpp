#ifndef ENGINE_MOCK_RENDERER_HPP
#define ENGINE_MOCK_RENDERER_HPP

#include <gmock/gmock.h>
#include <render/irenderer.hpp>

class MockRenderer : public IRenderer {
    MOCK_METHOD(void, render_sprite, (const Sprite &, ITexture &, bool), (override, const));
};

#endif //ENGINE_MOCK_RENDERER_HPP
