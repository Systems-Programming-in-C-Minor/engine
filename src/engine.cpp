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

        _fps = static_cast<unsigned long>(round(
                1.0 / static_cast<double>(current_nanos - _time_after_last_frame) * 1e9));
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

void Engine::listen_keyboard_state() {
    const Uint8 *current_key_states = SDL_GetKeyboardState(nullptr);

    if (current_key_states[SDL_SCANCODE_0])
        return; // NUM_0
    if (current_key_states[SDL_SCANCODE_1])
        return; // NUM_1
    if (current_key_states[SDL_SCANCODE_2])
        return; // NUM_2
    if (current_key_states[SDL_SCANCODE_3])
        return; // NUM_3
    if (current_key_states[SDL_SCANCODE_4])
        return; // NUM_4
    if (current_key_states[SDL_SCANCODE_5])
        return; // NUM_5
    if (current_key_states[SDL_SCANCODE_6])
        return; // NUM_6
    if (current_key_states[SDL_SCANCODE_7])
        return; // NUM_7
    if (current_key_states[SDL_SCANCODE_8])
        return; // NUM_8
    if (current_key_states[SDL_SCANCODE_9])
        return; // NUM_9
    if (current_key_states[SDL_SCANCODE_A])
        return; // A
    if (current_key_states[SDL_SCANCODE_B])
        return; // B
    if (current_key_states[SDL_SCANCODE_C])
        return; // C
    if (current_key_states[SDL_SCANCODE_D])
        return; // D
    if (current_key_states[SDL_SCANCODE_E])
        return; // E
    if (current_key_states[SDL_SCANCODE_F])
        return; // F
    if (current_key_states[SDL_SCANCODE_G])
        return; // G
    if (current_key_states[SDL_SCANCODE_H])
        return; // H
    if (current_key_states[SDL_SCANCODE_I])
        return; // I
    if (current_key_states[SDL_SCANCODE_J])
        return; // J
    if (current_key_states[SDL_SCANCODE_K])
        return; // K
    if (current_key_states[SDL_SCANCODE_L])
        return; // L
    if (current_key_states[SDL_SCANCODE_M])
        return; // M
    if (current_key_states[SDL_SCANCODE_N])
        return; // N
    if (current_key_states[SDL_SCANCODE_O])
        return; // O
    if (current_key_states[SDL_SCANCODE_P])
        return; // P
    if (current_key_states[SDL_SCANCODE_Q])
        return; // Q
    if (current_key_states[SDL_SCANCODE_R])
        return; // R
    if (current_key_states[SDL_SCANCODE_S])
        return; // S
    if (current_key_states[SDL_SCANCODE_T])
        return; // T
    if (current_key_states[SDL_SCANCODE_U])
        return; // U
    if (current_key_states[SDL_SCANCODE_V])
        return; // V
    if (current_key_states[SDL_SCANCODE_W])
        return; // W
    if (current_key_states[SDL_SCANCODE_X])
        return; // X
    if (current_key_states[SDL_SCANCODE_Y])
        return; // Y
    if (current_key_states[SDL_SCANCODE_Z])
        return; // Z
    if (current_key_states[SDL_SCANCODE_UP])
        return; // UP
    if (current_key_states[SDL_SCANCODE_RIGHT])
        return; // RIGHT
    if (current_key_states[SDL_SCANCODE_DOWN])
        return; // DOWN
    if (current_key_states[SDL_SCANCODE_LEFT])
        return; // LEFT
    if (current_key_states[SDL_SCANCODE_SPACE])
        return; // SPACE
    if (current_key_states[SDL_SCANCODE_RETURN])
        return; // ENTER
    if (current_key_states[SDL_SCANCODE_MINUS])
        return; // MIN
    if (current_key_states[SDL_SCANCODE_EQUALS])
        return; // EQUAL
    if (current_key_states[SDL_SCANCODE_RSHIFT])
        return; // SHIFT_RIGHT
    if (current_key_states[SDL_SCANCODE_LSHIFT])
        return; // SHIFT_LEFT
    if (current_key_states[SDL_SCANCODE_RCTRL])
        return; // CTRL_RIGHT
    if (current_key_states[SDL_SCANCODE_LCTRL])
        return; // CTRL_LEFT
    if (current_key_states[SDL_SCANCODE_RALT])
        return; // ALT_RIGHT
    if (current_key_states[SDL_SCANCODE_LALT])
        return; // ALT_LEFT
    if (current_key_states[SDL_SCANCODE_TAB])
        return; // TAB
    if (current_key_states[SDL_SCANCODE_ESCAPE])
        return; // ESC
}

