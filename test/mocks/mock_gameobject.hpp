#ifndef ENGINE_MOCK_GAMEOBJECT_H_4LY8uw2Eo3
#define ENGINE_MOCK_GAMEOBJECT_H_4LY8uw2Eo3

#include "gameobject.hpp"

#include "gmock/gmock.h"

class MockGameObject final : public GameObject {
public:
	MockGameObject(const std::string& name, const std::string& tag) : GameObject(name, tag) {}

	MOCK_METHOD(void, tick, (), (override));
	MOCK_METHOD(void, render, (), (override, const));
};

#endif // ENGINE_MOCK_GAMEOBJECT_H_4LY8uw2Eo3
