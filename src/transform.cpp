#include "transform.hpp"
#include "box2d/box2d.h"
#include "components/rigidbody.hpp"
#include "gameobject.hpp"

Transform::Transform(const Vector2d &position, float angle, float scale) :
        _position(position),
        _angle(angle),
        _scale(scale) {}

float Transform::get_angle() const {
    return _angle;
}

void Transform::set_angle(float angle) {
    _angle = angle;
}

float Transform::get_scale() const {
    return _scale;
}

void Transform::set_scale(float scale) {
    _scale = scale;
}

Vector2d Transform::get_position() const {
    auto rigid_body = get_rigid_body();
    if (rigid_body)
        return rigid_body->get_world_position();

    return _position;
}

void Transform::set_position(Vector2d &position) {
    auto rigid_body = get_rigid_body();
    if (rigid_body) {
//        rigid_body->get_world_position();
        return;
    }

    _position = position;
}

std::shared_ptr<RigidBody> Transform::get_rigid_body() const {
    if (!_game_object)
        return nullptr;

    return _game_object->get_component<RigidBody>();
}
