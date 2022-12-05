#include "../include/listeners/key_listener.hpp"

KeyListener::KeyListener(EventManager &manager) {
    manager.register_listener(KeyPressed, [this](const IEvent &event) {
        on_key_pressed(dynamic_cast<const KeyPressedEvent &>(event));
    });
    manager.register_listener(KeyReleased, [this](const IEvent &event) {
        on_key_released(dynamic_cast<const KeyReleasedEvent &>(event));
    });
}
