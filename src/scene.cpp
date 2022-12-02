#include "gameobject.hpp"
#include "scene.hpp"
#include "box2d/box2d.h"
#include "global.hpp"

void Scene::tick() {
    Global::get_instance()->time.tick();
    for (auto &gameobject: gameobjects) {
        gameobject->tick();
    }
}

void Scene::render(IRenderer &renderer) const {
    for (auto &gameobject: gameobjects) {
        gameobject->render(renderer);
    }
}

Scene::~Scene() = default;

Scene::Scene() : _world(std::make_unique<b2World>(b2Vec2(0.0f, 0.0f))) {};
