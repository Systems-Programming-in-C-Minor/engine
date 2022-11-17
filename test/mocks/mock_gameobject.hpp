#ifndef ENGINE_MOCK_GAMEOBJECT_H_4LY8uw2Eo3
#define ENGINE_MOCK_GAMEOBJECT_H_4LY8uw2Eo3

#include "gameobject.hpp"

#include "gmock/gmock.h"

class MockGameObject final : public GameObject {
public:
	MockGameObject(const std::string& name, const std::string& tag, bool is_world_space = true) : GameObject(name, tag, is_world_space) {}

	MOCK_METHOD(void, tick, (), (override));
	MOCK_METHOD(void, render, (IRenderer&), (override, const));
};

#endif // ENGINE_MOCK_GAMEOBJECT_H_4LY8uw2Eo3
