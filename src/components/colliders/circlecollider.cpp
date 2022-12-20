#include "components/colliders/circlecollider.hpp"
#include "box2d/box2d.h"
#include "utils/trigonometry.hpp"
#include <cmath>

CircleCollider::CircleCollider(float radius, bool ignore_collision_physics) : Collider(), _radius(radius)
{
    _ignore_collision_physics = ignore_collision_physics;
}

float CircleCollider::get_radius() const {
    return _radius;
}

std::vector<Vector2d> CircleCollider::get_vertices(b2Body& body, const Transform & transform) const
{
	const Vector2d center = transform.get_position();
    std::vector<Vector2d> vectors;
    
    // https://stackoverflow.com/a/27518647/10787114
    const int num_segments = 15 * std::lround(sqrtf(_radius));

	const float theta = 2 * 3.1415926f / static_cast<float>(num_segments);
	const float c = cosf(theta);
	const float s = sinf(theta);
	float x = _radius;
    float y = 0;
    for(int ii = 0; ii < num_segments; ii++)
    {
        vectors.emplace_back(x + center.x, y + center.y);
        const float t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }

    const Vector2d start_vertex = vectors[0];
    vectors.push_back(start_vertex);
    return vectors;
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