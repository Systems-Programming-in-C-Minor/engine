#ifndef ENGINE_MOCK_TICKABLE_COMPONENT_HPP
#define ENGINE_MOCK_TICKABLE_COMPONENT_HPP

#include <gmock/gmock.h>
#include <interfaces/irenderable.hpp>

class MockTickableComponent : public Component, public ITickable {
public:
    MOCK_METHOD(void, tick, (GameObject & ), (override, const));
};

#endif //ENGINE_MOCK_TICKABLE_COMPONENT_HPP
