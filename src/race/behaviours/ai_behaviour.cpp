#include "race/behaviours/ai_behaviour.hpp"
#include "gameobject.hpp"
#include "vector2d.hpp"
#include <math.h>
#include <fmt/core.h>

AIBehaviour::~AIBehaviour() = default;

void AIBehaviour::move_to_target() {
    if (reached_target){
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
    direction_to_target.normalize2();

    float dot = Vector2d::dot(forward, direction_to_target);


    if ( dot > 0 ) {
        drive_forwards();
    } else {
        drive_backwards();
    }

    float angle_to_dir = Vector2d::signed_angle(forward, direction_to_target, Vector2d(0,1));

    if( angle_to_dir > 0) {
        turn_left();
    } else {
        turn_right();
    }
}

void AIBehaviour::set_target(std::shared_ptr<GameObject> game_object) {
    _target = game_object;
}

void AIBehaviour::tick(GameObject &gameObject) {
    CarBehaviour::tick(gameObject);
    move_to_target();
}
