#include "race/behaviours/ai_behaviour.hpp"
#include "gameobject.hpp"
#include "vector2d.hpp"
#include <math.h>

AIBehaviour::~AIBehaviour() = default;

void AIBehaviour::move_to_target() {
    if (reached_target){
        return;
    }
    float forward_amount = 0.f;
    float turn_amount = 0.f;

    //Get current position
    const Vector2d current_position = game_object->transform.get_position();
    const Vector2d target_position = _target->transform.get_position();

    const auto angle = game_object->transform.get_angle();
    const auto x_forward = cos(angle);
    const auto y_forward = sin(angle);
    const Vector2d forward = Vector2d(x_forward, y_forward);

    float distance_to_target = Vector2d::distance(current_position, target_position);

    if(distance_to_target > reached_target_distance) {
        //Get direction to target
        const Vector2d direction_to_target = target_position - current_position;
        direction_to_target.normalize();
        float dot = Vector2d::dot(forward, direction_to_target);

        //Move to target
        if ( dot > 0 ) {
//            forward_amount = forward_speed;
            drive_forwards();

//            // Hit the brakes when close to target
//            float current_speed = game_object->get_component<RigidBody>()->get_forward_velocity().length();
//            if(distance_to_target < stopping_distance && current_speed > stopping_speed){
//                forward_amount = -forward_speed;
//            }

        } else {
//            // Turn around instead of endlessly driving backwards
//            if (distance_to_target > reverse_distance) {
//                forward_amount = forward_speed;
//            } else {
//                forward_amount = -forward_speed;
//            }
//            forward_amount = -forward_speed;
            drive_backwards();
        }

        float angle_to_dir = Vector2d::signed_angle(forward, direction_to_target, Vector2d(0,1));
        if( angle_to_dir > 0) {
//            turn_amount = -turn_speed;
            turn_right();
        } else {
//            turn_amount = turn_speed;
            turn_left();
        }
    } else {
        //Reached target
        forward_amount = 0.f;
        turn_amount = 0.f;

        reached_target = true;
    }

//    CarBehaviour::drive(forward_amount);
//    CarBehaviour::turn(turn_amount);
}

void AIBehaviour::set_target(GameObject &gameObject) {
    _target = std::make_shared<GameObject>(gameObject);
}

void AIBehaviour::tick(GameObject &gameObject) {
    CarBehaviour::tick(gameObject);
    move_to_target();
}
