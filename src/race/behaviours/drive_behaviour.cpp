#include "race/behaviours/drive_behaviour.hpp"
#include <gameobject.hpp>
#include <utility>
#include <iostream>
#include <complex>
#include "global.hpp"

DriveBehaviour::DriveBehaviour(std::shared_ptr<RigidBody> body, bool is_enabled) : _body(std::move(body)),
                                                                                   is_enabled(is_enabled) {}

void DriveBehaviour::drive(float force) {
    if (!is_enabled)
        return;

    force = std::clamp(force, -1.f, 1.f);

    const auto speed = _body->get_current_speed();
    if (speed > 0 && force < 0) {
        brake(std::abs(force));
        return;
    }

    const auto force_multiplier = force > 0 ? drive_force_multiplier : drive_backwards_force_multiplier;
    const auto force_vec = _body->get_world_vector(Vector2d{0, 1}) * force * force_multiplier;
    _body->apply_force(force_vec, _body->get_world_center());
}

void DriveBehaviour::turn(float steering) {
    if (!is_enabled)
        return;

    if (steering == 0.f) return;

    auto speed = _body->get_current_speed();
    if (std::abs(speed) < minimum_driving_speed_for_turning) return;

    steering = std::clamp(steering, -1.f, 1.f);

    steering *= (speed / std::abs(speed));

    steering *= 1.f / std::pow(std::abs(speed), speed_to_turn_ratio);

    steering = std::min(0.5f, std::abs(steering)) * (steering / std::abs(steering));

    _body->apply_angular_impulse(-steering * steering_multiplier);
}

void DriveBehaviour::brake(float amount) {
    if (_body->get_current_speed() <= 0) return;

    amount = std::clamp(amount, 0.f, 1.f);

    auto vec = _body->get_forward_velocity();
    vec.normalize();

    const auto force_vec = vec * -1 * amount * break_force_multiplier;
    _body->apply_force(force_vec, _body->get_world_center());
}
