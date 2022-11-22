#include "components/rigidbody.hpp"
#include "scene.hpp"

void RigidBody::apply_force(Vector2d force) {
}

void RigidBody::apply_torque(float torque) {

}

void RigidBody::set_linear_velocity(Vector2d velocity) {

}

Vector2d RigidBody::get_linear_velocity() {
    return Vector2d(0, 0);
}

void RigidBody::set_angular_velocity(float angle) {

}

float RigidBody::get_angular_velocity() {
    return 0;
}

void RigidBody::apply_linear_impulse(Vector2d inpulse) {

}

void RigidBody::apply_angular_impulse(Vector2d impulse) {

}

double RigidBody::get_mass() {
    return 0;
}

void RigidBody::set_mass(double m) {

}

double RigidBody::get_gravity_scale() {
    return 0;
}

void RigidBody::set_gravity_scale(double gs) {

}

BodyType RigidBody::get_bodytype() {
    return static_cast<BodyType>(_body->GetType());
}

void RigidBody::set_bodytype(BodyType bt) {

}

RigidBody::RigidBody(Scene &scene, BodyType type, Vector2d vector, double gravity_scale) {
    b2BodyDef body_def;
    body_def.type = static_cast<b2BodyType>(type);
    body_def.position.Set(static_cast<float>(vector.x), static_cast<float>(vector.y));
    body_def.gravityScale = static_cast<float>(gravity_scale);
    _body = scene._world->CreateBody(&body_def);
}
