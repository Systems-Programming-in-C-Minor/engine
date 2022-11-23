#ifndef COLLIDERS_POLYGONCOLLIDER_HPP
#define COLLIDERS_POLYGONCOLLIDER_HPP

#include "vector2d.hpp"
#include "collider.hpp"

#include <vector>

class Vector2d;

class PolygonCollider : public Collider
{
private:
    std::vector<Vector2d> _points;

public:
    PolygonCollider(std::vector<Vector2d> points);
    PolygonCollider(std::string path);

    [[nodiscard]] std::vector<Vector2d> get_points() const;

    std::vector<Vector2d> construct_points(std::string path);
};

#endif //COLLIDERS_POLYGONCOLLIDER_HPP