#include "gameobject.hpp"
#include "scene.hpp"
#include "box2d/box2d.h"

void Scene::tick() {
    for (auto &gameobject: gameobjects) {
        gameobject->tick();
    }
}

void Scene::render() const {
    for (auto &gameobject: gameobjects) {
        gameobject->render();
    }
}

EventManager &Scene::get_event_manager() const {
    return *_event_manager;
}

Scene::~Scene() = default;

Scene::Scene() : _world(std::make_unique<b2World>(b2Vec2(0.0f, 0.0f))),
                 _event_manager(std::make_unique<EventManager>()) {}
