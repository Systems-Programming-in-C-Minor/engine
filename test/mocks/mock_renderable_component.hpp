#pragma once

#include <gmock/gmock.h>
#include <interfaces/irenderable.hpp>

class MockRenderableComponent : public Component, public IRenderable {
public:
    MOCK_METHOD(void, render, (IRenderer, bool), (override, const));
};
