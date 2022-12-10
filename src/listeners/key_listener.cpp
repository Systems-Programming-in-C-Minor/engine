#include "../include/listeners/key_listener.hpp"

KeyListener::KeyListener(EventManager &event_manager) {
    event_manager.register_listener(KeyPressed, [this](const IEvent &event) {
        on_key_pressed(dynamic_cast<const KeyPressedEvent &>(event));
    });
    event_manager.register_listener(KeyHold, [this](const IEvent &event) {
        on_key_hold(dynamic_cast<const KeyHoldEvent &>(event));
    });
    event_manager.register_listener(KeyReleased, [this](const IEvent &event) {
        on_key_released(dynamic_cast<const KeyReleasedEvent &>(event));
    });
}
