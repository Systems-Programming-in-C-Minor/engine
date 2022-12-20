	#include "box2d/box2d.h"
#include "components/colliders/polygoncollider.hpp"
#include "fmt/core.h"
#include "utils/xmlreader.hpp"

PolygonCollider::PolygonCollider(std::vector<Vector2d> points, bool ignore_collision_physics) : Collider()
{
	_ignore_collision_physics = ignore_collision_physics;
	_points = std::move(points);
}

PolygonCollider::PolygonCollider(const std::string& path, bool ignore_collision_physics) : Collider() {

    _ignore_collision_physics = ignore_collision_physics;
	get_points_from_file(path);
}

std::vector<Vector2d> PolygonCollider::get_points() const {
	return _points;
}

std::vector<Vector2d> PolygonCollider::get_vertices(b2Body& body, const Transform& transform) const
{
	const auto shape = dynamic_cast<b2PolygonShape*>(body.GetFixtureList()->GetShape());

	const int vertex_count = shape->m_count;

	std::vector<Vector2d> vectors;
	vectors.reserve(vertex_count);

	for (int i = 0; i < vertex_count; ++i) {
		vectors.push_back(static_cast<Vector2d>(body.GetWorldPoint(shape->m_vertices[i])));
	}

	const Vector2d start_vertex = vectors[0];
	vectors.push_back(start_vertex);

	return vectors;
}

void PolygonCollider::get_points_from_file(const std::string& path) {
    XmlReader xmlreader(path);
    _points = xmlreader.get_points_vec2d();
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