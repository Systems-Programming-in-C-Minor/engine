#pragma once

#include <gmock/gmock.h>
#include <interfaces/irenderable.hpp>

class MockTickableComponent : public Component, public ITickable {
public:
    MOCK_METHOD(void, tick, (GameObject & ), (override, const));
};
