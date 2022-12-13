#include <thread>
#include "gameobject.hpp"
#include "scene.hpp"
#include "box2d/box2d.h"

void Scene::tick() {
    for (auto &game_object: gameobjects) {
        game_object->tick();
    }
}

void Scene::tick_world() {
    _world->Step(1.f/60.f, 6.0f, 2.0f);
}

void Scene::render() const {
    for (auto &game_object: gameobjects) {
        game_object->render();
    }
}

EventManager &Scene::get_event_manager() const {
    return *_event_manager;
}

Scene::~Scene() = default;

Scene::Scene() : _event_manager(std::make_unique<EventManager>()),
                 _world(std::make_unique<b2World>(b2Vec2(0.0f, 0.0f))) {}
