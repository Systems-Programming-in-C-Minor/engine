
#ifndef DRIVE_INPUT_CONTROLLER_BEHAVIOUR_HPP
#define DRIVE_INPUT_CONTROLLER_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/joystick_listener.hpp>
#include "interfaces/itickable.hpp"
#include "race/objects/car.hpp"

/**
 * @brief Class which defines drive input controller behaviour.
 */
class DriveInputControllerBehaviour : public Component, public JoystickListener {
public:
    /**
     * @brief Explicit constructor.
     * @param event_manager The EventManager the behaviour will use to send and receive events.
     * @param joystick_id The id of the joystick.
     */
    explicit DriveInputControllerBehaviour(EventManager &event_manager, int joystick_id);

    /**
      * @brief This method will be called whenever the axis stays the same.
      * @param event The received JoystickAxisCurrentEvent.
      */
    void on_axis_current(const JoystickAxisCurrentEvent &event) override;

    /**
     * @brief This method will be called whenever a button is held.
     * @param event The received JoystickButtonHoldEvent.
     */
    void on_button_hold(const JoystickButtonHoldEvent &event) override;

private:
    const int _joystick_id;
};

#endif //DRIVE_INPUT_CONTROLLER_BEHAVIOUR_HPP
