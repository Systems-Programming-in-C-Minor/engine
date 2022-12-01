#include "global.hpp"

Global *Global::_instance = nullptr;

Global *Global::get_instance() {
    if (_instance == nullptr) {
        _instance = new Global(nullptr, nullptr);
    }

    return _instance;
}

Global::Global(std::unique_ptr<Engine> engine, std::unique_ptr<IProperties> properties) : _engine(std::move(engine)), _properties(std::move(properties)) {}

void Global::set_engine(std::unique_ptr<Engine> engine) {
    _engine = std::move(engine);
}

Engine &Global::get_engine() {
    return *_engine;
}

const Engine &Global::get_engine() const {
    return *_engine;
}

void Global::set_properties(std::unique_ptr<IProperties> properties) {
    _properties = std::move(properties);
}

IProperties &Global::get_properties() {
    return *_properties;
}

const IProperties &Global::get_properties() const {
    return *_properties;
}

Scene &Global::get_active_scene() {
    return _engine->get_active_scene();
}

const Scene &Global::get_active_scene() const {
    return _engine->get_active_scene();
}
