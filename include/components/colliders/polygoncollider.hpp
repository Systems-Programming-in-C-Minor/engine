#ifndef COLLIDERS_POLYGONCOLLIDER_HPP
#define COLLIDERS_POLYGONCOLLIDER_HPP

#include "vector2d.hpp"
#include "collider.hpp"
#include "utils/collidernormalenum.hpp"

#include <vector>

class b2ChainShape;

class Vector2d;

/**
 * Collider class for polygonal objects
 */

class PolygonCollider : public Collider
{
public:
    explicit PolygonCollider(std::vector<Vector2d> points, ColliderNormal collider_normal = ColliderNormal::outwards);
    explicit PolygonCollider(const std::string& path, ColliderNormal collider_normal = ColliderNormal::outwards);

    [[nodiscard]] std::vector<Vector2d> get_points() const;

private:
    std::shared_ptr<b2ChainShape> _shape;
    std::vector<Vector2d> _points;

    void get_points_from_file(const std::string& path);
    void set_shape(ColliderNormal collider_normal);
};

#endif //COLLIDERS_POLYGONCOLLIDER_HPP