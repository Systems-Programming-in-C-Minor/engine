#include "gameobject.hpp"
#include "scene.hpp"
#include "box2d/box2d.h"

void Scene::tick() {
    _world->Step(1.f/60.f, 6.0f, 2.0f);

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
