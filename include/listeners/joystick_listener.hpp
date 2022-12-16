#ifndef ENGINE_IJOYSTICK_HPP
#define ENGINE_IJOYSTICK_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

class JoystickListener {
protected:
    explicit JoystickListener(EventManager &event_manager);

public:
    virtual void on_button_pressed(const JoystickButtonPressedEvent &event) {};

    virtual void on_button_hold(const JoystickButtonHoldEvent &event) {};

    virtual void on_button_released(const JoystickButtonReleasedEvent &event) {};

    virtual void on_axis_changed(const JoystickAxisChangedEvent &event) {};

    virtual void on_axis_current(const JoystickAxisCurrentEvent &event) {};
};

#endif //ENGINE_IJOYSTICK_HPP
