#include "transform.hpp"
#include "box2d/box2d.h"
#include "components/rigidbody.hpp"
#include "gameobject.hpp"
#include <nlohmann/json.hpp>
#include "json_converters.hpp"


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

void Transform::set_position(Vector2d position) {
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

void Transform::set_local_position(Vector2d new_position) {
    _local_position = new_position;
}

float Transform::get_local_angle() const {
    return _local_angle;
}

void Transform::set_local_angle(float angle) {
    _local_angle = angle;
}

std::shared_ptr<RigidBody> Transform::get_rigid_body() const {
    if (!_game_object)
        return nullptr;

    return _game_object->get_component<RigidBody>();
}

void Transform::deserialize(const std::string &data) {
    const auto j = nlohmann::json::parse(data);
    set_angle(j.at("angle").get<float>());
    set_scale(j.at("scale").get<float>());
    set_position(j.at("position").get<Vector2d>());
    set_local_position(j.at("local_position").get<Vector2d>());
    set_local_angle(j.at("local_angle").get<float>());
}

std::string Transform::serialize() const {
    return nlohmann::json{
            {"angle",          get_angle()},
            {"scale",          get_scale()},
            {"position",       get_position()},
            {"local_position", get_local_position()},
            {"local_angle",    get_local_angle()},
    }.dump();
}
