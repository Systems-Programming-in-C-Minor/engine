#include "color.hpp"
#include "engine.hpp"
#include <utility>
#include <chrono>
#include <cmath>
#include <SDL.h>
#include <thread>
#include "gameobject.hpp"
#include "sdlrenderer.hpp"
#include "managers/host_multiplayer_manager.hpp"
#include "managers/client_multiplayer_manager.hpp"
#include "fmt/core.h"

void Engine::load_scene(std::shared_ptr<Scene> new_scene) {
    _active_scene = std::move(new_scene);
}

void Engine::start() {
    _multiplayer_manager->initialize();

    while (!_should_quit) {
        SDL_PumpEvents();
        auto start_time = std::chrono::steady_clock::now();
        auto end_time = start_time + std::chrono::duration<int, std::ratio<1, 60>>(1) * _time_scale;

        _renderer->clear(Color(0.0, 0.0, 0.0, 255.0));
        _key_handler->tick();
        _mouse_handler->tick();
        _active_scene->tick();
        _multiplayer_manager->tick();
        _active_scene->tick();
        _active_scene->tick_world();
        _active_scene->render();
        _renderer->push_to_screen();
        _time->tick();

        const auto current_nanos = std::chrono::system_clock::now().time_since_epoch().count();

        _fps = static_cast<unsigned long>(round(
                1.0 / static_cast<double>(current_nanos - _time_after_last_frame) * 1e9));
        _time_after_last_frame = current_nanos;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_APP_TERMINATING) {
                stop();
            }
        }
        std::this_thread::sleep_until(end_time);
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

Time &Engine::get_time() const {
    return *_time;
}

std::shared_ptr<IRenderer> Engine::get_renderer() const {
    return _renderer;
}

Engine::Engine() : Engine(std::make_shared<SdlRenderer>()) {}

Engine::Engine(std::shared_ptr<IRenderer> renderer) : Engine(std::move(renderer), "engine-host") {}

Engine::Engine(const std::string &user_id, bool is_host) : Engine(std::make_shared<SdlRenderer>(), user_id, is_host) {}

Engine::Engine(std::shared_ptr<IRenderer> renderer, const std::string &user_id, bool is_host) :
        _should_quit(false), _time_after_last_frame(0), _fps(0),
        _time(std::make_shared<Time>()),
        _renderer(std::move(renderer)),
        _key_handler(std::make_shared<KeyHandler>()),
        _mouse_handler(std::make_shared<MouseHandler>()) {
    if (is_host)
        _multiplayer_manager = std::make_shared<HostMultiplayerManager>(user_id);
    else
        _multiplayer_manager = std::make_shared<ClientMultiplayerManager>(user_id);
}

unsigned long Engine::get_number_of_controllers() const {
    return _key_handler->get_number_of_controllers();
}

void Engine::set_time_scale(double time_scale) {
    _time_scale = time_scale;
}

double Engine::get_time_scale() {
    return _time_scale;
}

Engine::~Engine() = default;
