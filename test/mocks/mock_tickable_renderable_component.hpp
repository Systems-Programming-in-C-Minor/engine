#ifndef ENGINE_MOCK_TICKABLE_RENDERABLE_COMPONENT_HPP
#define ENGINE_MOCK_TICKABLE_RENDERABLE_COMPONENT_HPP

#include <gmock/gmock.h>
#include <interfaces/irenderable.hpp>

class MockTickableRenderableComponent : public Component, public ITickable, public IRenderable {
public:
    MOCK_METHOD(void, tick, (GameObject & ), (override, const));
    MOCK_METHOD(void, render, (IRenderer & , bool), (override, const));
};

#endif //ENGINE_MOCK_TICKABLE_RENDERABLE_COMPONENT_HPP
