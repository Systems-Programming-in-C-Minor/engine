#include "race/behaviours/friction_behaviour.hpp"
#include <gameobject.hpp>
#include "global.hpp"

void FrictionBehaviour::tick(GameObject &object) {
    _friction();
}

void FrictionBehaviour::_friction() {
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
    float currentForwardSpeed = currentForwardNormal.normalized_length();
    float dragForceMagnitude = -2 * currentForwardSpeed * drag_modifier;

    auto force_vec = currentForwardNormal * traction * dragForceMagnitude;

    body.apply_force(force_vec, body.get_world_center());
}
