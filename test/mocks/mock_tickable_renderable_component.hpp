#pragma once

#include <gmock/gmock.h>
#include <interfaces/irenderable.hpp>

class MockTickableRenderableComponent : public Component, public ITickable, public IRenderable{
public:
    MOCK_METHOD(void, tick, (GameObject & ), (override, const));
    MOCK_METHOD(void, render, (IRenderer, bool), (override, const));
};
