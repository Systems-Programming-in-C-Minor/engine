
#ifndef DRIVE_INPUT_BEHAVIOUR_HPP
#define DRIVE_INPUT_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/key_listener.hpp>
#include "interfaces/itickable.hpp"

class Car;

/**
 * @brief Class which defines drive key binds.
 */
class DriveKeybinds {
public:
    /**
     * @brief Explicit constructor.
     * @param forward The drive forward key bind value. Standard = W.
     * @param backwards The drive backwards key bind value. Standard = S.
     * @param left The drive left key bind value. Standard = A.
     * @param right The drive right key bind value. Standard = D.
     * @param brake The brake key bind value. Standard = SPACE.
     */
    explicit DriveKeybinds(Key forward = W, Key backwards = S, Key left = A, Key right = D, Key brake = SPACE);

    const Key forward;
    const Key backwards;
    const Key left;
    const Key right;
    const Key brake;
};

/**
 * @brief Class which defines drive input behaviour.
 */
class DriveInputBehaviour : public Component, public KeyListener {
public:
    /**
     * @brief Explicit constructor.
     * @param event_manager The EventManager the behaviour will use to send and receive events.
     * @param keybinds The DriveKeyBinds object of the behaviour.
     */
    explicit DriveInputBehaviour(EventManager &event_manager, DriveKeybinds keybinds = DriveKeybinds());

    /**
     * @brief This method will be called whenever a key is pressed.
     * @param event The received KeyPressedEvent.
     */
    void on_key_pressed(const KeyPressedEvent &event) override;

    /**
     * @brief This method will be called whenever a pressed key is held.
     * @param event The received KeyHoldEvent.
     */
    void on_key_hold(const KeyHoldEvent &event) override;

    /**
     * @brief This method will be called whenever a pressed key is released again.
     * @param event The received KeyReleasedEvent.
     */
    void on_key_released(const KeyReleasedEvent &event) override;

private:
    const DriveKeybinds _keybinds;
};

#endif //DRIVE_INPUT_BEHAVIOUR_HPP
