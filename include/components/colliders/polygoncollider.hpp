#ifndef COLLIDERS_POLYGONCOLLIDER_HPP
#define COLLIDERS_POLYGONCOLLIDER_HPP

#include "vector2d.hpp"
#include "collider.hpp"
#include "utils/collidernormalenum.hpp"

#include <vector>

class b2ChainShape;
class b2Body;
class Vector2d;

/**
 * Collider class for polygonal objects
 */

class PolygonCollider : public Collider
{
public:
    explicit PolygonCollider(std::vector<Vector2d> points, bool ignore_collision_physics = false, ColliderNormal collider_normal = ColliderNormal::outwards);
    explicit PolygonCollider(const std::string& path, bool ignore_collision_physics = false, ColliderNormal collider_normal = ColliderNormal::outwards);

    [[nodiscard]] std::vector<Vector2d> get_points() const;
protected:
    void set_fixture(b2Body& body, float friction, float restitution) override;
private:
    ColliderNormal _collider_normal;

    void get_points_from_file(const std::string& path);
};

#endif //COLLIDERS_POLYGONCOLLIDER_HPP