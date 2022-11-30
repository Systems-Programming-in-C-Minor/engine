#include "gameobject.hpp"
#include "scene.hpp"


void Scene::tick()
{
	for (auto& gameobject : gameobjects) {
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

Scene::Scene() = default;