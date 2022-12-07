#include "../include/listeners/key_listener.hpp"
#include "global.hpp"

KeyListener::KeyListener() {
    Global::get_instance()->get_engine()
            .event_manager->register_listener(KeyPressed, [this](const IEvent &event) {
        on_key_pressed(dynamic_cast<const KeyPressedEvent &>(event));
    });
    Global::get_instance()->get_engine()
            .event_manager->register_listener(KeyReleased, [this](const IEvent &event) {
        on_key_released(dynamic_cast<const KeyReleasedEvent &>(event));
    });
}
