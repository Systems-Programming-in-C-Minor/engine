
#ifndef DRIVE_INPUT_BEHAVIOUR_HPP
#define DRIVE_INPUT_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/key_listener.hpp>
#include "interfaces/itickable.hpp"

class Car;

class DriveKeybinds {
public:
    explicit DriveKeybinds(Key forward = W, Key backwards = S, Key left = A, Key right = D, Key brake = SPACE);

    const Key forward;
    const Key backwards;
    const Key left;
    const Key right;
    const Key brake;
};

class DriveInputBehaviour : public Component, public KeyListener {
public:
    explicit DriveInputBehaviour(EventManager &event_manager, DriveKeybinds keybinds = DriveKeybinds());

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_hold(const KeyHoldEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

private:
    const DriveKeybinds _keybinds;
};

#endif //DRIVE_INPUT_BEHAVIOUR_HPP
