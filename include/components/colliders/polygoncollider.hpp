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
    PolygonCollider();
    explicit PolygonCollider(std::vector<Vector2d> points);

    [[nodiscard]] std::vector<Vector2d> get_points() const;
    void set_points(std::vector<Vector2d> p);
};

#endif //COLLIDERS_POLYGONCOLLIDER_HPP