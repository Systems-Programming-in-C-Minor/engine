#ifndef ENGINE_IJOYSTICK_HPP
#define ENGINE_IJOYSTICK_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

/**
 * @brief Interface for objects wanting to respond to joystick events.
 */
class JoystickListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param event_manager The manager which registers listeners and notifies subscribers.
     */
    explicit JoystickListener(EventManager &event_manager);

public:
    /**
     * @brief This method will be called whenever a button is pressed.
     *        Override for implementing the desired behaviour.
     * @param event The desired JoystickButtonPressedEvent.
     */
    virtual void on_button_pressed(const JoystickButtonPressedEvent &event) {};

    /**
     * @brief This method will be called whenever a button is held.
     *        Override for implementing the desired behaviour.
     * @param event The desired JoystickButtonHoldEvent.
     */
    virtual void on_button_hold(const JoystickButtonHoldEvent &event) {};

    /**
     * @brief This method will be called whenever a button is released.
     *        Override for implementing the desired behaviour.
     * @param event The desired JoystickButtonReleasedEvent.
     */
    virtual void on_button_released(const JoystickButtonReleasedEvent &event) {};

    /**
     * @brief This method will be called whenever the axis is changed.
     *        Override for implementing the desired behaviour.
     * @param event The desired JoystickAxisChangedEvent.
     */
    virtual void on_axis_changed(const JoystickAxisChangedEvent &event) {};

    /**
     * @brief This method will be called whenever the axis stays the same.
     *        Override for implementing the desired behaviour.
     * @param event The desired JoystickAxisCurrentEvent.
     */
    virtual void on_axis_current(const JoystickAxisCurrentEvent &event) {};
};

#endif //ENGINE_IJOYSTICK_HPP
