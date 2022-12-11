#include "box2d/box2d.h"
#include "components/colliders/chaincollider.hpp"
#include "fmt/core.h"

ChainCollider::ChainCollider(std::vector<Vector2d> points, bool ignore_collision_physics ,ColliderNormal collider_normal) : Collider(), _collider_normal(collider_normal)
{
    _ignore_collision_physics = ignore_collision_physics;
    _points = std::move(points);
}

ChainCollider::ChainCollider(const std::string& path, bool ignore_collision_physics, ColliderNormal collider_normal) : Collider(), _collider_normal(collider_normal) {
    _ignore_collision_physics = ignore_collision_physics;
	get_points_from_file(path);
}

std::vector<Vector2d> ChainCollider::get_points() const {
    return _points;
}

void ChainCollider::get_points_from_file(const std::string& path) {
    /*
     * TODO Task: Implement SpriteCollider
     * https://app.clickup.com/t/377pt9y
     */
    _points = std::vector<Vector2d>{Vector2d{}};
}

void ChainCollider::set_fixture(b2Body& body, float friction, float restitution) {
    std::vector<b2Vec2> vectors;
    vectors.reserve(_points.size());

    if (_collider_normal == ColliderNormal::outwards) {
        for (auto i = _points.rbegin(); i != _points.rend(); ++i) {  // NOLINT(modernize-loop-convert)
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
    fixture_def.density = 1.f;
    body.CreateFixture(&fixture_def);
}