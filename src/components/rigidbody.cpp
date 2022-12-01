#include "components/rigidbody.hpp"
#include "scene.hpp"

#include "box2d/box2d.h"

RigidBody::RigidBody(const Scene &scene, const BodyType type, const Vector2d vector, const float gravity_scale) {
    b2BodyDef body_def;
    body_def.type = static_cast<b2BodyType>(type);
    body_def.position.Set(vector.x, vector.y);
    body_def.gravityScale = gravity_scale;
    _body = scene._world->CreateBody(&body_def);
}

void RigidBody::apply_force(const Vector2d force, const Vector2d point) const {
    _body->ApplyForce(get_b2vec(force), get_b2vec(point), false);
}

void RigidBody::apply_torque(const float torque) const {
    _body->ApplyTorque(torque, false);
}

void RigidBody::set_linear_velocity(const Vector2d velocity) const {
    _body->SetLinearVelocity(get_b2vec(velocity));
}

Vector2d RigidBody::get_linear_velocity() const {
    return get_vec(_body->GetLinearVelocity());
}

void RigidBody::set_angular_velocity(const float angle) const {
    _body->SetAngularVelocity(angle);
}

float RigidBody::get_angular_velocity() const {
    return _body->GetAngularVelocity();
}

void RigidBody::apply_linear_impulse(const Vector2d impulse, const Vector2d point) const {
    _body->ApplyLinearImpulse(get_b2vec(impulse), get_b2vec(point), false);
}

void RigidBody::apply_angular_impulse(const float impulse) const {
    _body->ApplyAngularImpulse(impulse, false);
}

float RigidBody::get_mass() const {
    return _body->GetMass();
}

float RigidBody::get_inertia() const {
    return _body->GetInertia();
}

void RigidBody::set_mass(const float mass) const {
    b2MassData *data {};
    _body->GetMassData(data);
    data->mass = mass;
    _body->SetMassData(data);
}

float RigidBody::get_gravity_scale() const {
    return _body->GetGravityScale();
}

void RigidBody::set_gravity_scale(const float gravity_scale) const {
    _body->SetGravityScale(gravity_scale);
}

BodyType RigidBody::get_body_type() const {
    return static_cast<BodyType>(_body->GetType());
}

void RigidBody::set_body_type(const BodyType body_type) const {
    _body->SetType(static_cast<b2BodyType>(body_type));
}

b2Vec2 RigidBody::get_b2vec(const Vector2d vector) {
    return {vector.x, vector.y};
}

Vector2d RigidBody::get_vec(const b2Vec2 vector) {
    return Vector2d(vector.x, vector.y);
}
