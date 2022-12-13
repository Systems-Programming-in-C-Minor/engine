#include "components/colliders/circlecollider.hpp"
#include "box2d/box2d.h"

CircleCollider::CircleCollider(Vector2d point, float radius) : _radius(radius) {
    _points = {point};
}

double CircleCollider::get_radius() const {
    return _radius;
}

void CircleCollider::set_fixture(b2Body &body, float friction, float restitution) {

    b2CircleShape shape;
    shape.m_p.Set(_points.at(0).x, _points.at(0).y);
    shape.m_radius = _radius;
    b2FixtureDef fixture_def{};
    fixture_def.restitution = restitution;
    fixture_def.friction = friction;
    fixture_def.shape = &shape;
    fixture_def.isSensor = _ignore_collision_physics;
    fixture_def.density = 1.f;
    body.CreateFixture(&fixture_def);
}