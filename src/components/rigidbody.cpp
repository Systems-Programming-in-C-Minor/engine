#include "components/colliders/collider.hpp"
#include "components/rigidbody.hpp"
#include "global.hpp"
#include "scene.hpp"
#include "../rendercall.hpp"

#include "box2d/box2d.h"

RigidBody::RigidBody(const Scene &scene,
                     int order_in_layer,
                     const BodyType type,
                     const Vector2d vector,
                     const float gravity_scale,
                     const float restitution,
                     const float friction
) :
        IRenderable(order_in_layer),
        _restitution(restitution),
        _friction(friction) {
    b2BodyDef body_def;
    body_def.type = static_cast<b2BodyType>(type);
    body_def.position.Set(vector.x, vector.y);
    body_def.gravityScale = gravity_scale;
    body_def.userData.pointer = reinterpret_cast<std::uintptr_t>(this);
    _body = scene._world->CreateBody(&body_def);
}

void RigidBody::apply_force(const Vector2d force, const Vector2d point) const {
    _body->ApplyForce(get_b2vec(force), get_b2vec(point), true);
}

void RigidBody::apply_torque(const float torque) const {
    _body->ApplyTorque(torque, true);
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
    _body->ApplyLinearImpulse(get_b2vec(impulse), get_b2vec(point), true);
}

void RigidBody::apply_angular_impulse(const float impulse) const {
    _body->ApplyAngularImpulse(impulse, true);
}

Vector2d RigidBody::get_world_vector(const Vector2d vector) const {
    return get_vec(_body->GetWorldVector(get_b2vec(vector)));
}

Vector2d RigidBody::get_lateral_velocity() {
    b2Vec2 current_right_normal = _body->GetWorldVector(b2Vec2(1, 0));
    return get_vec(b2Dot(current_right_normal, _body->GetLinearVelocity()) * current_right_normal);
}

Vector2d RigidBody::get_forward_velocity() {
    b2Vec2 currentForwardNormal = _body->GetWorldVector(b2Vec2(0, 1));
    return get_vec(b2Dot(currentForwardNormal, _body->GetLinearVelocity()) * currentForwardNormal);
}

Vector2d RigidBody::get_direction() {
    return get_vec(_body->GetWorldVector(b2Vec2(0, 1)));
}

float RigidBody::get_current_speed() {
    Vector2d currentForwardNormal = get_world_vector(Vector2d{0, 1});
    return b2Dot(get_b2vec(get_forward_velocity()), get_b2vec(currentForwardNormal));
}

Vector2d RigidBody::get_world_center() {
    return get_vec(_body->GetWorldCenter());
}

void RigidBody::set_mass(const float mass) const {
    auto data = b2MassData{};
    _body->GetMassData(&data);
    data.mass = mass;
    _body->SetMassData(&data);
}

float RigidBody::get_mass() const {
    return _body->GetMass();
}

float RigidBody::get_inertia() const {
    return _body->GetInertia();
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

void RigidBody::set_position(Vector2d vector) const {
    _body->SetTransform(get_b2vec(vector), _body->GetAngle());
}

Vector2d RigidBody::get_position() const {
    return get_vec(_body->GetPosition());
}

void RigidBody::set_angle(float angle) const {
    _body->SetTransform(_body->GetPosition(), angle);
}

float RigidBody::get_angle() const {
    return _body->GetAngle();
}

void RigidBody::set_collider(const std::shared_ptr<Collider> &collider) {
    _collider = collider;
    collider->set_fixture(*_body, _friction, _restitution);
}

b2Body *RigidBody::get_body() const {
    return _body;
}

void RigidBody::render(bool is_world_space) const {
    const auto renderer = Global::get_instance()->get_engine().get_renderer();
    renderer->render_rigid_body(*this, game_object->transform, true);

    auto render_call = RenderCall([this, renderer, transform = game_object->transform, is_world_space]() {
        renderer->render_rigid_body(*this, game_object->transform, is_world_space);
    }, _order_in_layer);
    renderer->add_render_call(render_call);
}
