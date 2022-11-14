#include "scene.hpp"

void Scene::tick()
{
	for (auto& gameobject : gameobjects) {
		// TODO Call tick on gameobject here. Missing tick func
	}
}

void Scene::render()
{
	for (auto& gameobject : gameobjects) {
		// TODO Render gameobjects here. Missing render func and renderer
	}
}

Scene::Scene() {};