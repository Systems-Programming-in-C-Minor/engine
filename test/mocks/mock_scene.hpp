#ifndef ENGINE_MOCK_SCENE_HPP
#define ENGINE_MOCK_SCENE_HPP

#include "gmock/gmock.h"
#include "scene.hpp"

class MockScene final : public Scene {
public:
	MOCK_METHOD(void, tick, (), (override));
	MOCK_METHOD(void, render, (IRenderer&), (override, const));
};

#endif // ENGINE_MOCK_SCENE_HPP
