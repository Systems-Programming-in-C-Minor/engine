#include "race/behaviours/ai_behaviour.hpp"
#include "gameobject.hpp"
#include "vector2d.hpp"
#include <utility>
#include <cmath>
#include "global.hpp"
#include "events.hpp"
#include "utils/random.hpp"
#include "race/objects/car.hpp"

AIBehaviour::~AIBehaviour() = default;

void AIBehaviour::move_to_target() {
    if(!_target){
        return;
    }

    if (reached_target){
        auto target_reached = AITargetReachedEvent(*this, _target);
        Global::get_instance()->notify_event_manager(target_reached);
        return;
    }

    //Get current position
    const Vector2d current_position = game_object->transform.get_position();
    const Vector2d target_position = _target->transform.get_position();

    const auto angle = game_object->transform.get_angle();
    const auto x_forward = -sin(angle);
    const auto y_forward = cos(angle);
    auto forward = Vector2d(x_forward, y_forward);

    Vector2d direction_to_target = target_position - current_position;
    direction_to_target.normalize();

    float dot = Vector2d::dot(forward, direction_to_target);
    float distance_to_target = Vector2d::distance(current_position, target_position);

    float angle_to_dir = Vector2d::signed_angle(forward, direction_to_target, Vector2d(0,1));

    const auto behaviour = reinterpret_cast<Car *>(game_object);

    if (dot > 0 || distance_to_target > reverse_distance)
        behaviour->drive_forwards();
    else behaviour->drive_backwards();

    if (angle_to_dir > max_angle_to_direction)
        behaviour->turn_left();
    if(angle_to_dir < -max_angle_to_direction)
        behaviour->turn_right();

    if(distance_to_target < reached_target_distance)
        reached_target = true;
}

void AIBehaviour::set_target(std::shared_ptr<GameObject> game_object) {
    _target = std::move(game_object);
    const auto oldpos = _target->transform.get_position();
    const auto newpos = oldpos + Vector2d(Random::random_float(-_offset,_offset), Random::random_float(-_offset,_offset));
    _target->transform.set_position(newpos);
    reached_target = false;
}

void AIBehaviour::tick(GameObject &gameObject) {
    move_to_target();
}

float AIBehaviour::get_offset() {
    return _offset;
}

void AIBehaviour::set_offset(float offset) {
    _offset = offset;
}

AIBehaviour::AIBehaviour(std::shared_ptr<GameObject> target) {
    _target = std::move(target);
}
