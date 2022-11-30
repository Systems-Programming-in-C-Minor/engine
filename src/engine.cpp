#include "color.hpp"
#include "engine.hpp"
#include <utility>
#include <chrono>
#include <cmath>
#include "gameobject.hpp"
#include "global.hpp"
#include "sdlrenderer.hpp"
#include "SDL.h"



void Engine::load_scene(std::shared_ptr<Scene> new_scene) {
    _active_scene = std::move(new_scene);
}

void Engine::start() {
    while (!_should_quit) {
        _renderer->clear(Color(0.0, 0.0, 0.0, 255.0));
        _active_scene->tick();
        _active_scene->render();
    	_renderer->push_to_screen();

        const auto current_nanos = std::chrono::system_clock::now().time_since_epoch().count();

        _fps = static_cast<unsigned long>(round(1.0 / static_cast<double>(current_nanos - _time_after_last_frame) * 1e9));
        _time_after_last_frame = current_nanos;
    }
}

void Engine::stop() {
    _should_quit = true;
}

Scene &Engine::get_active_scene() {
    return *_active_scene;
}

const Scene &Engine::get_active_scene() const {
    return *_active_scene;
}

unsigned long Engine::get_fps() const {
    return _fps;
}

std::shared_ptr<IRenderer> Engine::get_renderer() const
{
    return _renderer;
}

Engine::Engine() : Engine(std::make_shared<SdlRenderer>())
{}

Engine::Engine(std::shared_ptr<IRenderer> renderer) : _should_quit(false), _time_after_last_frame(0), _fps(0), _renderer(std::move(renderer))
{}

Engine::~Engine() = default;
