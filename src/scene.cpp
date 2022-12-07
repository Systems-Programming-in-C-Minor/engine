#include "gameobject.hpp"
#include "scene.hpp"
#include "global.hpp"
#include "box2d/box2d.h"

void Scene::tick() {
    Global::get_instance()->time.tick();
    for (auto &gameobject: gameobjects) {
        gameobject->tick();
        Global::get_instance()->time.tick();
    }
}

void Scene::render(IRenderer &renderer) const {
    for (auto &gameobject: gameobjects) {
        gameobject->render(renderer);
    }
}

EventManager &Scene::get_event_manager() const {
    return *_event_manager;
}

Scene::~Scene() = default;

Scene::Scene() : _world(std::make_unique<b2World>(b2Vec2(0.0f, 0.0f))) {};
