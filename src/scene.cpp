#include "gameobject.hpp"
#include "scene.hpp"
#include "box2d/box2d.h"

void Scene::tick() {
    for (auto &gameobject: gameobjects) {
        gameobject->tick();
    }
}

void Scene::render() const
{
	for (auto& gameobject : gameobjects) {
		gameobject->render();
	}
}

Scene::~Scene() = default;

Scene::Scene() : _world(std::make_unique<b2World>(b2Vec2(0.0f, 0.0f))) {};
