#ifndef ENGINE_MOCK_RENDERABLE_COMPONENT_HPP
#define ENGINE_MOCK_RENDERABLE_COMPONENT_HPP

#include <gmock/gmock.h>	
#include <interfaces/irenderable.hpp>

class MockRenderableComponent : public Component, public IRenderable {
public:
	explicit MockRenderableComponent(int order_in_layer) : IRenderable(order_in_layer) {}
	MOCK_METHOD(void, set_active, (bool), (override));
	MOCK_METHOD(void, render, (), (override));
	MOCK_METHOD(int, get_order_in_layer, (), (override));
};

#endif //ENGINE_MOCK_RENDERABLE_COMPONENT_HPP
