#include "race/behaviours/drive_input_behaviour.hpp"
#include "race/objects/car.hpp"

DriveInputBehaviour::DriveInputBehaviour(EventManager &event_manager, const DriveKeybinds keybinds) : KeyListener(
        event_manager), _keybinds(keybinds) {}

void DriveInputBehaviour::on_key_pressed(const KeyPressedEvent &event) {}

void DriveInputBehaviour::on_key_hold(const KeyHoldEvent &event) {
    const auto car = reinterpret_cast<Car *>(game_object);
    if (event.key == _keybinds.forward) {
        car->drive(1);
        return;
    }
    if (event.key == _keybinds.backwards) {
        car->drive(-1);
        return;
    }
    if (event.key == _keybinds.left) {
        car->turn(-1);
        return;
    }
    if (event.key == _keybinds.right) {
        car->turn(1);
        return;
    }
    if (event.key == _keybinds.brake) {
        car->brake();
        return;
    }
}

void DriveInputBehaviour::on_key_released(const KeyReleasedEvent &event) {}

DriveKeybinds::DriveKeybinds(const Key forward, const Key backwards, const Key left, const Key right, const Key brake)
        : forward(forward), backwards(backwards), left(left), right(right), brake(brake) {
}
