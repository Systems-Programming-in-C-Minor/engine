#include "components/colliders/circlecollider.hpp"
#include "box2d/box2d.h"

CircleCollider::CircleCollider(float radius, bool ignore_collision_physics) : Collider(), _radius(radius)
{
    _ignore_collision_physics = ignore_collision_physics;
}

float CircleCollider::get_radius() const {
    return _radius;
}

void CircleCollider::set_fixture(b2Body &body, float friction, float restitution) {
    b2CircleShape shape;
    shape.m_p.Set(0.f, 0.f);
    shape.m_radius = _radius;
    b2FixtureDef fixture_def{};
    fixture_def.restitution = restitution;
    fixture_def.friction = friction;
    fixture_def.shape = &shape;
    fixture_def.isSensor = _ignore_collision_physics;
    fixture_def.density = 1.f;
    body.CreateFixture(&fixture_def);
}