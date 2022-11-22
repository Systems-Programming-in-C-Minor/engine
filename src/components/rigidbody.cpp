#include "components/rigidbody.hpp"
#include "scene.hpp"
#include "box2d/box2d.h"

void RigidBody::apply_force(Vector2d force, Vector2d point) {
    _body->ApplyForce(get_b2vec(force), get_b2vec(point), false);
}

void RigidBody::apply_torque(float torque) {
    _body->ApplyTorque(torque, false);
}

void RigidBody::set_linear_velocity(Vector2d velocity) {
    _body->SetLinearVelocity(get_b2vec(velocity));
}

Vector2d RigidBody::get_linear_velocity() {
    return get_vec(_body->GetLinearVelocity());
}

void RigidBody::set_angular_velocity(float angle) {
    _body->SetAngularVelocity(angle);
}

float RigidBody::get_angular_velocity() {
    _body->GetAngularVelocity();
}

void RigidBody::apply_linear_impulse(Vector2d impulse, Vector2d point) {
    _body->ApplyLinearImpulse(get_b2vec(impulse), get_b2vec(point), false);
}

void RigidBody::apply_angular_impulse(float impulse) {
    _body->ApplyAngularImpulse(impulse, false);
}

float RigidBody::get_mass() {
    _body->GetMass();
}

float RigidBody::get_inertia() {
    _body->GetInertia();
}

void RigidBody::set_mass(float mass) {
    b2MassData *data;
    _body->GetMassData(data);
    data->mass = mass;
    _body->SetMassData(data);
}

float RigidBody::get_gravity_scale() {
    return _body->GetGravityScale();
}

void RigidBody::set_gravity_scale(float gravity_scale) {
    _body->SetGravityScale(gravity_scale);
}

BodyType RigidBody::get_body_type() {
    return static_cast<BodyType>(_body->GetType());
}

void RigidBody::set_body_type(BodyType body_type) {
    _body->SetType(static_cast<b2BodyType>(body_type));
}

RigidBody::RigidBody(Scene &scene, BodyType type, Vector2d vector, float gravity_scale) {
    b2BodyDef body_def;
    body_def.type = static_cast<b2BodyType>(type);
    body_def.position.Set(vector.x, vector.y);
    body_def.gravityScale = gravity_scale;
    _body = scene._world->CreateBody(&body_def);
}

b2Vec2 RigidBody::get_b2vec(Vector2d vector) {
    return b2Vec2(vector.x, vector.y);
}

Vector2d RigidBody::get_vec(b2Vec2 vector) {
    return Vector2d(vector.x, vector.y);
}
