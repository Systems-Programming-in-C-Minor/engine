#include "handlers/mouse_handler.hpp"
#include <algorithm>
#include "../include/global.hpp"
#include "SDL.h"
#include "events.hpp"

std::vector<MouseInput> MouseHandler::fetch_input() {
    const Uint32 current_mouse_states = SDL_GetMouseState(&_x, &_y);

    std::vector<MouseInput> button_pressed;

    if (current_mouse_states & SDL_BUTTON_LEFT)
        button_pressed.emplace_back(BUTTON_LEFT);
    if (current_mouse_states & SDL_BUTTON_MIDDLE)
        button_pressed.emplace_back(BUTTON_MIDDLE);
    if (current_mouse_states & SDL_BUTTON_RIGHT)
        button_pressed.emplace_back(BUTTON_RIGHT);

    return button_pressed;
}

void MouseHandler::tick() {
    int old_x = _x;
    int old_y = _y;
    auto input_pressed = fetch_input();

    for (const auto pressed_key: input_pressed) {
        if (std::find(_input_active.begin(), _input_active.end(), pressed_key) == _input_active.end())
            continue;

        auto pressed_event = MousePressedEvent(pressed_key);
        Global::get_instance()->notify_event_manager(pressed_event);
    }

    for (const auto active_key: _input_active) {
        if (std::find(input_pressed.begin(), input_pressed.end(), active_key) == input_pressed.end())
            continue;

        auto release_event = MouseReleasedEvent(active_key);
        Global::get_instance()->notify_event_manager(release_event);
    }

    if (old_x != _x || old_y != _y) {
        auto moved_event = MouseMovedEvent(_x, _y);
        Global::get_instance()->notify_event_manager(moved_event);
    }


    _input_active = input_pressed;
}