
#ifndef DRIVE_INPUT_CONTROLLER_BEHAVIOUR_HPP
#define DRIVE_INPUT_CONTROLLER_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/joystick_listener.hpp>
#include "interfaces/itickable.hpp"
#include "race/objects/car.hpp"

class DriveInputControllerBehaviour : public Component, public JoystickListener {
public:
    explicit DriveInputControllerBehaviour(EventManager &event_manager, int joystick_id);

    void on_axis_current(const JoystickAxisCurrentEvent &event) override;

    void on_button_hold(const JoystickButtonHoldEvent &event) override;

private:
    const int _joystick_id;
};

#endif //DRIVE_INPUT_CONTROLLER_BEHAVIOUR_HPP
