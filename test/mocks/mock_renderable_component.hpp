#ifndef ENGINE_MOCK_RENDERABLE_COMPONENT_HPP
#define ENGINE_MOCK_RENDERABLE_COMPONENT_HPP

#include <gmock/gmock.h>
#include <interfaces/irenderable.hpp>

class MockRenderableComponent : public Component, public IRenderable {
public:
    MOCK_METHOD(void, render, (IRenderer & , bool), (override, const));
};

#endif //ENGINE_MOCK_RENDERABLE_COMPONENT_HPP
