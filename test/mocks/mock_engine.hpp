#ifndef ENGINE_MOCK_ENGINE_HPP
#define ENGINE_MOCK_ENGINE_HPP

#include "gmock/gmock.h"
#include "engine.hpp"

class MockEngine : public Engine {
public:
    MOCK_METHOD(const Scene &, get_active_scene, (), (override, const));
    MOCK_METHOD(Scene &, get_active_scene, (), (override));
};

#endif // ENGINE_MOCK_ENGINE_HPP
