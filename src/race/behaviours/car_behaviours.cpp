#include "race/behaviours/car_behaviour.hpp"
#include <gameobject.hpp>

CarBehaviour::CarBehaviour() {}

void CarBehaviour::tick(GameObject &object) {
    friction();
}

void CarBehaviour::friction() {
    auto &body = *game_object->get_component<RigidBody>();

    //calculate the counter lateral impulse based on drift parameters
    Vector2d impulse = body.get_lateral_velocity() * -body.get_mass();
    if (impulse.length() > max_lateral_impulse)
        impulse = impulse * (max_lateral_impulse / impulse.length());

    // apply the impulse
    body.apply_linear_impulse(impulse * drift_friction, body.get_world_center());

    //angular velocity
    body.apply_angular_impulse(angular_friction * body.get_inertia() * -body.get_angular_velocity());

    //forward linear velocity
    Vector2d currentForwardNormal = body.get_forward_velocity();
    float currentForwardSpeed = currentForwardNormal.normalize();
    float dragForceMagnitude = -2 * currentForwardSpeed * drag_modifier;

    body.apply_force(currentForwardNormal * current_traction * dragForceMagnitude, body.get_world_center());
}

void CarBehaviour::drive(float desired_speed) {
    auto &body = *game_object->get_component<RigidBody>();

    //find current speed in forward direction
    float current_speed = body.get_current_speed();

    //apply necessary force
    float force = (desired_speed > current_speed) ? max_drive_force : -max_drive_force;
    if (desired_speed != current_speed) {
        auto force_vec = body.get_world_vector(Vector2d{0, 1}) * current_traction * force;
        body.apply_force(force_vec, body.get_world_center());
    }
}

void CarBehaviour::turn_left() {
    game_object->get_component<RigidBody>()->apply_angular_impulse(steering_impulse);
}

void CarBehaviour::turn_right() {
    game_object->get_component<RigidBody>()->apply_angular_impulse(-steering_impulse);
}

void CarBehaviour::drive_forwards() {
    drive(max_speed_forwards);
}

void CarBehaviour::drive_backwards() {
    drive(max_speed_backwards);
}