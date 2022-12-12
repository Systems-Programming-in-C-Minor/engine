#include "box2d/box2d.h"
#include "components/colliders/polygoncollider.hpp"
#include "fmt/core.h"
#include "utils/xmlreader.hpp"

PolygonCollider::PolygonCollider(std::vector<Vector2d> points, bool ignore_collision_physics ,ColliderNormal collider_normal) : Collider(), _collider_normal(collider_normal)
{
    _ignore_collision_physics = ignore_collision_physics;
    _points = std::move(points);
}

PolygonCollider::PolygonCollider(const std::string& path, bool ignore_collision_physics, ColliderNormal collider_normal) : Collider(), _collider_normal(collider_normal) {

    _ignore_collision_physics = ignore_collision_physics;
	get_points_from_file(path);
}

std::vector<Vector2d> PolygonCollider::get_points() const {
    return _points;
}

void PolygonCollider::get_points_from_file(const std::string& path) {
    XmlReader xmlreader(path);
    _points = xmlreader.get_points_vec2d();
}

void PolygonCollider::set_fixture(b2Body& body, float friction, float restitution) {
    std::vector<b2Vec2> vectors;

    if (_collider_normal == ColliderNormal::outwards) {
        for (auto i = _points.rbegin(); i != _points.rend(); ++i) {
            vectors.push_back(static_cast<b2Vec2>(*i));
        }
    }

    else if (_collider_normal == ColliderNormal::inwards) {
        for (auto& vector2d : _points) {
            vectors.push_back(static_cast<b2Vec2>(vector2d));
        }
    }

    b2ChainShape shape;
    shape.CreateLoop(vectors.data(), static_cast<int>(vectors.size()));
    b2FixtureDef fixture_def{};
    fixture_def.restitution = restitution;
    fixture_def.friction = friction;
    fixture_def.shape = &shape;
    fixture_def.isSensor = _ignore_collision_physics;
    body.CreateFixture(&fixture_def);
}