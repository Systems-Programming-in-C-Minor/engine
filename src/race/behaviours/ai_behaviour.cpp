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

    Vector2d forward(-1.f,0.f);

//    const auto angle =
//    const auto x_forward = cos(angle);
//    const auto y_forward = sin(angle);
//    forward = Vector2d(x_forward, y_forward);

    Vector2d direction_to_target = target_position - current_position;
    direction_to_target.normalize();

    float dot = Vector2d::dot(forward, direction_to_target);
    fmt::print("{}\n", dot);

    if ( dot > 0 ) {
        drive_forwards();
    } else {
        drive_backwards();
    }

    float angle_to_dir = Vector2d::signed_angle(forward, direction_to_target, Vector2d(0,1));
    if( angle_to_dir > 0) {
        turn_right();
    } else {
        turn_left();
    }
}

void AIBehaviour::set_target(GameObject &gameObject) {
    _target = std::make_shared<GameObject>(gameObject);
}

void AIBehaviour::tick(GameObject &gameObject) {
    CarBehaviour::tick(gameObject);
    move_to_target();
}
