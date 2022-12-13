#ifndef ENGINE_MOCK_RENDERABLE_COMPONENT_HPP
#define ENGINE_MOCK_RENDERABLE_COMPONENT_HPP

#include <gmock/gmock.h>	
#include <interfaces/irenderable.hpp>

class MockRenderableComponent : public Component, public IRenderable {
public:
	explicit MockRenderableComponent(int order_in_layer) : IRenderable(order_in_layer) {}
    MOCK_METHOD(void, render, (bool), (override, const));
};

#endif //ENGINE_MOCK_RENDERABLE_COMPONENT_HPP
