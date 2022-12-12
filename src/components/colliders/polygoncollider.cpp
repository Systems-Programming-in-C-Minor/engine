#include "box2d/box2d.h"
#include "components/colliders/polygoncollider.hpp"
#include "fmt/core.h"

PolygonCollider::PolygonCollider(std::vector<Vector2d> points, bool ignore_collision_physics) : Collider()
{
	_ignore_collision_physics = ignore_collision_physics;
	_points = std::move(points);
}

PolygonCollider::PolygonCollider(const std::string& path, bool ignore_collision_physics) : Collider()
{
	_ignore_collision_physics = ignore_collision_physics;
	get_points_from_file(path);
}

std::vector<Vector2d> PolygonCollider::get_points() const {
	return _points;
}

void PolygonCollider::get_points_from_file(const std::string& path) {
	/*
	 * TODO Task: Implement SpriteCollider
	 * https://app.clickup.com/t/377pt9y
	 */
	_points = std::vector<Vector2d>{Vector2d{}};
}

void PolygonCollider::set_fixture(b2Body& body, float friction, float restitution) {
	std::vector<b2Vec2> vectors;
	vectors.reserve(_points.size());

	for (auto i = _points.rbegin(); i != _points.rend(); ++i) {  // NOLINT(modernize-loop-convert)
			vectors.push_back(static_cast<b2Vec2>(*i));
	}

	b2PolygonShape shape;
	shape.Set(vectors.data(), static_cast<int>(vectors.size()));
	b2FixtureDef fixture_def{};
	fixture_def.restitution = restitution;
	fixture_def.friction = friction;
	fixture_def.shape = &shape;
	fixture_def.isSensor = _ignore_collision_physics;
	fixture_def.density = 1.f;
	body.CreateFixture(&fixture_def);
}