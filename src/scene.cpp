#include <thread>
#include <utility>
#include "gameobject.hpp"
#include "scene.hpp"
#include "handlers/collision_handler.hpp"
#include "camera.hpp"
#include "global.hpp"

void Scene::tick() {
    const auto scene = &Global::get_instance()->get_engine().get_active_scene();
    for (auto &game_object: gameobjects) {
        if (scene != &Global::get_instance()->get_engine().get_active_scene())
            return;
        game_object->tick();
    }
}

void Scene::tick_world() {
    _world->Step(1.f / 60.f, 6.0f, 2.0f);
}

void Scene::render() const {
    for (auto &game_object: gameobjects) {
        game_object->render();
    }
}

EventManager &Scene::get_event_manager() const {
    return *_event_manager;
}

std::shared_ptr<Camera> Scene::get_camera() const {
    return _camera;
}

std::string Scene::get_name() const {
    return _name;
}

void Scene::set_camera(std::shared_ptr<Camera> camera) {
    _camera = std::move(camera);
}

Scene::~Scene() = default;

Scene::Scene(std::shared_ptr<Camera> camera, std::string name) :
        _event_manager(std::make_unique<EventManager>()),
        _world(std::make_unique<b2World>(b2Vec2(0.0f, 0.0f))),
        _collision_handler(std::make_unique<CollisionHandler>()),
        _camera(std::move(camera)),
        _name(std::move(name)) {
    _world->SetContactListener(_collision_handler.get());
    gameobjects.push_back(_camera);
}
