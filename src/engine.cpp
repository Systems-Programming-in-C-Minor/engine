#include "engine.hpp"

#include <utility>
#include <chrono>
#include <cmath>
#include <SDL.h>
#include <thread>
#include "gameobject.hpp"
#include "sdlrenderer.hpp"
#include "audio/sdl_mixer_sound_engine.hpp"
#include "fmt/core.h"
#include "utils/thread_wait.hpp"
#include "networking/multiplayer_client.hpp"

void Engine::load_scene(std::shared_ptr<Scene> new_scene) {
    _active_scene = std::move(new_scene);
}

void Engine::start() {
    while (!_should_quit) {
        ThreadWait thread_wait{_tps};

        SDL_PumpEvents();
        _renderer->clear();
        _key_handler->tick();
        _mouse_handler->tick();

        if (multiplayer_manager != nullptr)
            multiplayer_manager->tick();

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
        thread_wait.wait();
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

int Engine::get_ticks_per_second() const {
    return _tps;
}

void Engine::set_ticks_per_second(int tps) {
    _tps = tps;
}

std::shared_ptr<IRenderer> Engine::get_renderer() const {
    return _renderer;
}

std::shared_ptr<ISoundEngine> Engine::get_sound_engine() const {
    return _sound_engine;
}

Engine::Engine() : Engine(std::make_shared<SdlRenderer>(), std::make_shared<SDLMixerSoundEngine>()) {}

Engine::Engine(std::shared_ptr<IRenderer> renderer, std::shared_ptr<ISoundEngine> sound_engine) :
        _should_quit(false),
        _time(std::make_shared<Time>()),
        _key_handler(std::make_shared<KeyHandler>()),
        _mouse_handler(std::make_shared<MouseHandler>()),
        _renderer(std::move(renderer)),
        _sound_engine(std::move(sound_engine)),
        _time_after_last_frame(0),
        _fps(0),
        _tps(60) {}

unsigned long Engine::get_number_of_controllers() const {
    return _key_handler->get_number_of_controllers();
}

void Engine::enable_multiplayer(const std::string &signalling_server) {
    multiplayer_manager = std::make_unique<MultiplayerClient>(signalling_server);
}

void Engine::disable_multiplayer() {
    multiplayer_manager.reset();
}

Engine::~Engine() = default;
