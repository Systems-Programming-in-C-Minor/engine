#include "engine.hpp"

#include <utility>
#include <chrono>
#include <cmath>
#include <SDL_keyboard.h>
#include "gameobject.hpp"


void Engine::load_scene(std::shared_ptr<Scene> new_scene) {
    _active_scene = std::move(new_scene);
}

void Engine::start() {
    while (!_should_quit) {
        _active_scene->tick();
        _active_scene->render(*_renderer);

        const auto current_nanos = std::chrono::system_clock::now().time_since_epoch().count();

        _fps = static_cast<unsigned long>(round(1.0 / static_cast<double>(current_nanos - _time_after_last_frame) * 1e9));
        _time_after_last_frame = current_nanos;
    }
}

void Engine::stop() {
    _should_quit = true;
}

Scene &Engine::get_active_scene() const {
    return *_active_scene;
}

unsigned long Engine::get_fps() const {
    return _fps;
}

void Engine::listenKeyboardState() {
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);

    if (currentKeyStates[SDL_SCANCODE_0])
        return;
}

