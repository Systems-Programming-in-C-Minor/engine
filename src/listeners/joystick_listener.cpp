#include "listeners/joystick_listener.hpp"

JoystickListener::JoystickListener(EventManager &event_manager) {
    event_manager.register_listener(JoystickButtonPressed, [this](const IEvent &event) {
        on_button_pressed(dynamic_cast<const JoystickButtonPressedEvent &>(event));
    });
    event_manager.register_listener(JoystickButtonHold, [this](const IEvent &event) {
        on_button_hold(dynamic_cast<const JoystickButtonHoldEvent &>(event));
    });
    event_manager.register_listener(JoystickButtonReleased, [this](const IEvent &event) {
        on_button_released(dynamic_cast<const JoystickButtonReleasedEvent &>(event));
    });
    event_manager.register_listener(JoystickAxisChanged, [this](const IEvent &event) {
        on_axis_changed(dynamic_cast<const JoystickAxisChangedEvent &>(event));
    });
    event_manager.register_listener(JoystickAxisCurrent, [this](const IEvent &event) {
        on_axis_current(dynamic_cast<const JoystickAxisCurrentEvent &>(event));
    });
}
