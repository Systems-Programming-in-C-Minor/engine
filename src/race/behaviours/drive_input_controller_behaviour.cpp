#include "race/behaviours/drive_input_controller_behaviour.hpp"
#include "race/objects/car.hpp"

DriveInputControllerBehaviour::DriveInputControllerBehaviour(EventManager &event_manager, const int joystick_id)
        : JoystickListener(event_manager), _joystick_id(joystick_id) {}

void DriveInputControllerBehaviour::on_axis_current(const JoystickAxisCurrentEvent &event) {
    if (event.joystick_id != _joystick_id)
        return;
    const auto car = reinterpret_cast<Car *>(game_object);
    switch (event.axis) {
        case LeftJoystickX:
        case LeftTouchpadX: {
            if (std::abs(event.value) > 0.1f) {
                car->turn(-event.value);
            }
            break;
        }
        case LeftTrigger: {
            if (event.value > -0.9) {
                car->drive_backwards((event.value + 1.0f) / 2);
            }
            break;
        }
        case RightTrigger: {
            if (event.value > -0.9) {
                car->drive_forwards((event.value + 1.0f) / 2);
            }
            break;
        }
        default:
            break;
    }
}

void DriveInputControllerBehaviour::on_button_hold(const JoystickButtonHoldEvent &event) {
    if (event.joystick_id != _joystick_id)
        return;
    const auto car = reinterpret_cast<Car *>(game_object);
    if (event.button == LeftButton) {
        car->brake();
    }
}
