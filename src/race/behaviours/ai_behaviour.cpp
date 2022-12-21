#include "race/behaviours/ai_behaviour.hpp"
#include "gameobject.hpp"
#include "vector2d.hpp"
#include <utility>
#include <cmath>
#include <iostream>
#include "global.hpp"
#include "events.hpp"
#include "utils/random.hpp"
#include "race/objects/car.hpp"

AIBehaviour::~AIBehaviour() = default;

void AIBehaviour::move_to_target() {
    if (!_target) {
        return;
    }

    if (reached_target) {
        auto target_reached = AITargetReachedEvent(*this, _target);
        Global::get_instance()->notify_event_manager(target_reached);
        return;
    }

    //Get current position
    const Vector2d current_position = game_object->transform.get_position();
    const Vector2d target_position = _target->transform.get_position();

    const auto angle = game_object->transform.get_angle();
    const auto x_forward = -std::sin(angle);
    const auto y_forward = std::cos(angle);
    auto forward = Vector2d(x_forward, y_forward);

    Vector2d direction_to_target = target_position - current_position;
    direction_to_target.normalize();

    float dot = Vector2d::dot(forward, direction_to_target);
    float distance_to_target = Vector2d::distance(current_position, target_position);

    float angle_to_dir = Vector2d::signed_angle(forward, direction_to_target, Vector2d(0, 1));

    const auto behaviour = reinterpret_cast<Car *>(game_object);

    const auto current_speed = behaviour->get_component<RigidBody>()->get_current_speed();

    const auto driving_force = std::clamp(0.15f / std::abs(angle_to_dir), .1f, .9f);

    if (dot > 0 || distance_to_target > reverse_distance) {
        if (current_speed > 8.f && std::abs(angle_to_dir) > .2f) {
            behaviour->brake(1);
        } else if (current_speed > 3.f && std::abs(angle_to_dir) > .8f) {
            behaviour->brake(1);
        } else {
            behaviour->drive(driving_force);
        }
    } else {
        behaviour->drive(-.9f);
    }

    if (std::abs(angle_to_dir) > max_angle_to_direction)
        behaviour->turn(-angle_to_dir * 3);

    if (distance_to_target < reached_target_distance)
        reached_target = true;
}

void AIBehaviour::set_target(std::shared_ptr<GameObject> game_object) {
    _target = std::move(game_object);
    const auto old_pos = _target->transform.get_position();
    _target->transform.set_position(old_pos + Vector2d(
            Random::random_float(-_offset, _offset),
            Random::random_float(-_offset, _offset)
    ));
    reached_target = false;
}

void AIBehaviour::tick(GameObject &gameObject) {
    move_to_target();
}

float AIBehaviour::get_offset() const {
    return _offset;
}

void AIBehaviour::set_offset(float offset) {
    _offset = offset;
}

AIBehaviour::AIBehaviour(std::shared_ptr<GameObject> target) {
    _target = std::move(target);
}
