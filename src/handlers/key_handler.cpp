#include "handlers/key_handler.hpp"
#include <algorithm>
#include <iostream>
#include "../include/global.hpp"
#include "SDL.h"
#include "events.hpp"

KeyHandler::KeyHandler() {
    int num_joysticks = SDL_NumJoysticks();
    std::cout << "Number of connected joysticks: " << num_joysticks << std::endl;

    for (int i = 0; i < num_joysticks; i++) {
        SDL_Joystick *joystick = SDL_JoystickOpen(i);
        if (joystick == nullptr) {
            std::cerr << "Error: Failed to open joystick " << i << ": " << SDL_GetError() << std::endl;
        } else {
            _joysticks.push_back(joystick);
            std::cout << "Joystick " << i << " name: " << SDL_JoystickName(joystick) << std::endl;
        }
    }
}

std::vector<Key> KeyHandler::fetch_keys() {
    const Uint8 *current_key_states = SDL_GetKeyboardState(nullptr);

    std::vector<Key> keys_pressed;

    if (current_key_states[SDL_SCANCODE_0])
        keys_pressed.emplace_back(NUM_0);
    if (current_key_states[SDL_SCANCODE_1])
        keys_pressed.emplace_back(NUM_1);
    if (current_key_states[SDL_SCANCODE_2])
        keys_pressed.emplace_back(NUM_2);
    if (current_key_states[SDL_SCANCODE_3])
        keys_pressed.emplace_back(NUM_3);
    if (current_key_states[SDL_SCANCODE_4])
        keys_pressed.emplace_back(NUM_4);
    if (current_key_states[SDL_SCANCODE_5])
        keys_pressed.emplace_back(NUM_5);
    if (current_key_states[SDL_SCANCODE_6])
        keys_pressed.emplace_back(NUM_6);
    if (current_key_states[SDL_SCANCODE_7])
        keys_pressed.emplace_back(NUM_7);
    if (current_key_states[SDL_SCANCODE_8])
        keys_pressed.emplace_back(NUM_8);
    if (current_key_states[SDL_SCANCODE_9])
        keys_pressed.emplace_back(NUM_9);
    if (current_key_states[SDL_SCANCODE_A])
        keys_pressed.emplace_back(A);
    if (current_key_states[SDL_SCANCODE_B])
        keys_pressed.emplace_back(B);
    if (current_key_states[SDL_SCANCODE_C])
        keys_pressed.emplace_back(C);
    if (current_key_states[SDL_SCANCODE_D])
        keys_pressed.emplace_back(D);
    if (current_key_states[SDL_SCANCODE_E])
        keys_pressed.emplace_back(E);
    if (current_key_states[SDL_SCANCODE_F])
        keys_pressed.emplace_back(F);
    if (current_key_states[SDL_SCANCODE_G])
        keys_pressed.emplace_back(G);
    if (current_key_states[SDL_SCANCODE_H])
        keys_pressed.emplace_back(H);
    if (current_key_states[SDL_SCANCODE_I])
        keys_pressed.emplace_back(I);
    if (current_key_states[SDL_SCANCODE_J])
        keys_pressed.emplace_back(J);
    if (current_key_states[SDL_SCANCODE_K])
        keys_pressed.emplace_back(K);
    if (current_key_states[SDL_SCANCODE_L])
        keys_pressed.emplace_back(L);
    if (current_key_states[SDL_SCANCODE_M])
        keys_pressed.emplace_back(M);
    if (current_key_states[SDL_SCANCODE_N])
        keys_pressed.emplace_back(N);
    if (current_key_states[SDL_SCANCODE_O])
        keys_pressed.emplace_back(O);
    if (current_key_states[SDL_SCANCODE_P])
        keys_pressed.emplace_back(P);
    if (current_key_states[SDL_SCANCODE_Q])
        keys_pressed.emplace_back(Q);
    if (current_key_states[SDL_SCANCODE_R])
        keys_pressed.emplace_back(R);
    if (current_key_states[SDL_SCANCODE_S])
        keys_pressed.emplace_back(S);
    if (current_key_states[SDL_SCANCODE_T])
        keys_pressed.emplace_back(T);
    if (current_key_states[SDL_SCANCODE_U])
        keys_pressed.emplace_back(U);
    if (current_key_states[SDL_SCANCODE_V])
        keys_pressed.emplace_back(V);
    if (current_key_states[SDL_SCANCODE_W])
        keys_pressed.emplace_back(W);
    if (current_key_states[SDL_SCANCODE_X])
        keys_pressed.emplace_back(X);
    if (current_key_states[SDL_SCANCODE_Y])
        keys_pressed.emplace_back(Y);
    if (current_key_states[SDL_SCANCODE_Z])
        keys_pressed.emplace_back(Z);
    if (current_key_states[SDL_SCANCODE_UP])
        keys_pressed.emplace_back(UP);
    if (current_key_states[SDL_SCANCODE_RIGHT])
        keys_pressed.emplace_back(RIGHT);
    if (current_key_states[SDL_SCANCODE_DOWN])
        keys_pressed.emplace_back(DOWN);
    if (current_key_states[SDL_SCANCODE_LEFT])
        keys_pressed.emplace_back(LEFT);
    if (current_key_states[SDL_SCANCODE_SPACE])
        keys_pressed.emplace_back(SPACE);
    if (current_key_states[SDL_SCANCODE_RETURN])
        keys_pressed.emplace_back(ENTER);
    if (current_key_states[SDL_SCANCODE_MINUS])
        keys_pressed.emplace_back(MIN);
    if (current_key_states[SDL_SCANCODE_EQUALS])
        keys_pressed.emplace_back(EQUAL);
    if (current_key_states[SDL_SCANCODE_RSHIFT])
        keys_pressed.emplace_back(SHIFT_RIGHT);
    if (current_key_states[SDL_SCANCODE_LSHIFT])
        keys_pressed.emplace_back(SHIFT_LEFT);
    if (current_key_states[SDL_SCANCODE_RCTRL])
        keys_pressed.emplace_back(CTRL_RIGHT);
    if (current_key_states[SDL_SCANCODE_LCTRL])
        keys_pressed.emplace_back(CTRL_LEFT);
    if (current_key_states[SDL_SCANCODE_RALT])
        keys_pressed.emplace_back(ALT_RIGHT);
    if (current_key_states[SDL_SCANCODE_LALT])
        keys_pressed.emplace_back(ALT_LEFT);
    if (current_key_states[SDL_SCANCODE_TAB])
        keys_pressed.emplace_back(TAB);
    if (current_key_states[SDL_SCANCODE_ESCAPE])
        keys_pressed.emplace_back(ESC);

    return keys_pressed;
}

void KeyHandler::tick() {
    auto keys_pressed = fetch_keys();

    for (const auto pressed_key: keys_pressed) {
        auto hold_event = KeyHoldEvent(pressed_key);

        if (std::find(_keys_active.begin(), _keys_active.end(), pressed_key) != _keys_active.end()) {
            Global::get_instance()->notify_event_manager(hold_event);
            continue;
        }

        auto pressed_event = KeyPressedEvent(pressed_key);
        Global::get_instance()->notify_event_manager(pressed_event);
        Global::get_instance()->notify_event_manager(hold_event);
    }

    for (const auto active_key: _keys_active) {
        if (std::find(keys_pressed.begin(), keys_pressed.end(), active_key) != keys_pressed.end())
            continue;

        auto release_event = KeyReleasedEvent(active_key);
        Global::get_instance()->notify_event_manager(release_event);
    }



    // Update joystick state
    SDL_JoystickUpdate();

    // Iterate over all joysticks
    for (auto &joystick: _joysticks) {
        _fire_joystick_axis_event_if_changed(LeftJoystickX, SDL_JoystickGetAxis(joystick, 0));
        _fire_joystick_axis_event_if_changed(LeftJoystickY, SDL_JoystickGetAxis(joystick, 1));

        _fire_joystick_axis_event_if_changed(LeftTrigger, SDL_JoystickGetAxis(joystick, 2));

        _fire_joystick_axis_event_if_changed(RightJoystickX, SDL_JoystickGetAxis(joystick, 3));
        _fire_joystick_axis_event_if_changed(RightJoystickY, SDL_JoystickGetAxis(joystick, 4));

        _fire_joystick_axis_event_if_changed(RightTrigger, SDL_JoystickGetAxis(joystick, 5));

        _fire_joystick_button_event_if_changed(AButton, SDL_JoystickGetButton(joystick, 0));
        _fire_joystick_button_event_if_changed(BButton, SDL_JoystickGetButton(joystick, 1));
        _fire_joystick_button_event_if_changed(XButton, SDL_JoystickGetButton(joystick, 2));
        _fire_joystick_button_event_if_changed(YButton, SDL_JoystickGetButton(joystick, 3));
        _fire_joystick_button_event_if_changed(LeftButton, SDL_JoystickGetButton(joystick, 4));
        _fire_joystick_button_event_if_changed(RightButton, SDL_JoystickGetButton(joystick, 5));
    }

    _keys_active = keys_pressed;
}

KeyHandler::~KeyHandler() {
    // Close all joysticks
    for (auto &joystick: _joysticks) {
        SDL_JoystickClose(joystick);
    }
}

void KeyHandler::_fire_joystick_button_event_if_changed(JoystickButton button, int value) {
    const auto previouslyPressed =
            std::find(_joystick_buttons_active.begin(), _joystick_buttons_active.end(), button) !=
            _joystick_buttons_active.end();
    if (value == 1) {
        Global::get_instance()->notify_event_manager(JoystickButtonHoldEvent(button));

        if (!previouslyPressed) {
            Global::get_instance()->notify_event_manager(JoystickButtonPressedEvent(button));
            _joystick_buttons_active.push_back(button);
        }
    } else {
        if (previouslyPressed) {
            Global::get_instance()->notify_event_manager(JoystickButtonReleasedEvent(button));
            _joystick_buttons_active.remove(button);
        }
    }
}

void KeyHandler::_fire_joystick_axis_event_if_changed(JoystickAxis axis, int value) {
    const auto normalized_value = _normalize_axis(value);

    Global::get_instance()->notify_event_manager(JoystickAxisCurrentEvent(axis, normalized_value));

    if (std::abs(_joystick_axes_values[axis] - normalized_value) > 0.1f) {
        Global::get_instance()->notify_event_manager(JoystickAxisChangedEvent(axis, normalized_value));
        _joystick_axes_values[axis] = normalized_value;
    }
}

float KeyHandler::_normalize_axis(int value) {
    return static_cast<float>(value + 32767) / 32767.0f - 1.0f;
}
