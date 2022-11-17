#pragma once

#include "vector2d.hpp"
#include "collider.hpp"

#include <vector>

class Vector2d;

class PolygonCollider : public Collider
{
private:
    std::vector<Vector2d> _points;

public:
    PolygonCollider();
    explicit PolygonCollider(std::vector<Vector2d> points);

    ~PolygonCollider() = default;

    std::vector<Vector2d> get_points();
    void set_points(std::vector<Vector2d> p);
};
