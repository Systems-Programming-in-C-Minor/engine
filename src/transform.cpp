#include "transform.hpp"
#include "box2d/box2d.h"
#include "components/rigidbody.hpp"
#include "gameobject.hpp"

Transform::Transform(const Vector2d &position, const Vector2d &local_position, float angle, float scale) :
        _position(position),
        _local_position(local_position),
        _angle(angle),
        _scale(scale) {}

float Transform::get_angle() const {
    auto rigid_body = get_rigid_body();
    if (rigid_body)
        return rigid_body->get_angle();

    return _angle;
}

void Transform::set_angle(float angle) {
    auto rigid_body = get_rigid_body();
    if (rigid_body) {
        rigid_body->set_angle(angle);
        return;
    }

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
        return rigid_body->get_position();

    return _position;
}

void Transform::set_position(Vector2d &position) {
    auto rigid_body = get_rigid_body();
    if (rigid_body) {
        rigid_body->set_position(position);
        return;
    }

    _position = position;
}

Vector2d Transform::get_local_position() const {
    return _local_position;
}

void Transform::set_local_position(Vector2d &new_position) {
    _local_position = std::move(new_position);
}

std::shared_ptr<RigidBody> Transform::get_rigid_body() const {
    if (!_game_object)
        return nullptr;

    return _game_object->get_component<RigidBody>();
}
