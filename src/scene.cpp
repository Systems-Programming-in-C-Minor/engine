#include "gameobject.hpp"
#include "scene.hpp"


void Scene::tick()
{
	for (auto& gameobject : gameobjects) {
		gameobject->tick();
	}
}

void Scene::render(IRenderer& renderer) const
{
	for (auto& gameobject : gameobjects) {
		gameobject->render(renderer);
	}
}

Scene::~Scene() = default;

Scene::Scene() = default;