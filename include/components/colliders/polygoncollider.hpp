#pragma once

//#include "Vector2d.hpp"
#include "collider.hpp"

#include <vector>

class Vector2d;

class PolygonCollider : public Collider
{
private:
    PolygonCollider();
    ~PolygonCollider();

    std::vector<Vector2d> _points;

public:
//    std::vector<Vector2d> get_points();
//    void set_points(std::vector<Vector2d> p);
};
