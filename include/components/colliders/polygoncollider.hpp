#ifndef COLLIDERS_POLYGONCOLLIDER_HPP
#define COLLIDERS_POLYGONCOLLIDER_HPP

#include "vector2d.hpp"
#include "collider.hpp"

#include <vector>

class Vector2d;

class PolygonCollider : public Collider
{
public:
    PolygonCollider(std::vector<Vector2d> points);
    PolygonCollider(const std::string& path);

    [[nodiscard]] std::vector<Vector2d> get_points() const;

private:
    std::vector<Vector2d> _points;

    void construct_points(const std::string& path);
};

#endif //COLLIDERS_POLYGONCOLLIDER_HPP