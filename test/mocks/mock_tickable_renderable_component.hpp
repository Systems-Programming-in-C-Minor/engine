#ifndef ENGINE_MOCK_TICKABLE_RENDERABLE_COMPONENT_HPP
#define ENGINE_MOCK_TICKABLE_RENDERABLE_COMPONENT_HPP

#include <gmock/gmock.h>
#include <interfaces/irenderable.hpp>
#include <interfaces/itickable.hpp>

class MockTickableRenderableComponent : public Component, public ITickable, public IRenderable {
public:
	explicit MockTickableRenderableComponent(int order_in_layer) : IRenderable(order_in_layer) {}
	MOCK_METHOD(void, set_active, (bool), (override));
	MOCK_METHOD(void, render, (), (override));
	MOCK_METHOD(int, get_order_in_layer, (), (override));
    MOCK_METHOD(void, tick, (GameObject &), (override));
};

#endif //ENGINE_MOCK_TICKABLE_RENDERABLE_COMPONENT_HPP
