#include "race/behaviours/drive_behaviour.hpp"
#include <gameobject.hpp>
#include <iostream>
#include <iomanip>
#include "global.hpp"

DriveBehaviour::DriveBehaviour(RigidBody &body) : _body(body) {}

void DriveBehaviour::_drive(float desired_speed){
    if(desired_speed > max_speed_forwards)
        desired_speed = max_speed_forwards;

    if (desired_speed < max_speed_backwards)
        desired_speed = max_speed_backwards;

    //find current speed in forward direction
    float current_speed = _body.get_current_speed();

    //apply necessary force
    float force = std::min(max_drive_force, std::max(-max_drive_force, (desired_speed/100 - current_speed) * max_drive_force));

//    float force = (desired_speed > current_speed) ? max_drive_force : -max_drive_force;
    if (desired_speed != current_speed) {
        auto force_vec = _body.get_world_vector(Vector2d{0, 1}) * drive_traction * force;
        _body.apply_force(force_vec, _body.get_world_center());
    }
}

void DriveBehaviour::_turn(float steering) {
    if (steering > steering_impulse)
        steering = steering_impulse;

    if(steering < -steering_impulse)
        steering = -steering_impulse;
    
    auto speed = _body.get_current_speed();

    if (speed < 0.5f && speed > -0.5f)
        return;

    if (speed < 0)
        steering *= -1;

    _body.apply_angular_impulse(steering);
}

void DriveBehaviour::turn_left(float amount) {
    turn(amount);
}

void DriveBehaviour::turn_right(float amount) {
    turn(-amount);
}

void DriveBehaviour::drive_forwards(float amount) {
    _drive(max_speed_forwards * amount);
}

void DriveBehaviour::drive_backwards(float amount) {
    _drive(max_speed_backwards * amount);
}

void DriveBehaviour::brake() {
    _drive(0.f);
}

void DriveBehaviour::turn(float amount) {
    _turn(steering_impulse * amount);
}
