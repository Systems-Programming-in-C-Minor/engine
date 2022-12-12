#ifndef COLLIDERS_CHAINCOLLIDER_HPP
#define COLLIDERS_CHAINCOLLIDER_HPP

#include "vector2d.hpp"
#include "collider.hpp"
#include "enums/collidernormal.hpp"

#include <vector>

class b2ChainShape;
class b2Body;
class Vector2d;

/**
 * Collider class for polygonal objects
 */

class ChainCollider : public Collider
{
public:
    explicit ChainCollider(std::vector<Vector2d> points, bool ignore_collision_physics = false, ColliderNormal collider_normal = ColliderNormal::outwards);
    explicit ChainCollider(const std::string& path, bool ignore_collision_physics = false, ColliderNormal collider_normal = ColliderNormal::outwards);

    [[nodiscard]] std::vector<Vector2d> get_points() const;
protected:
    void set_fixture(b2Body& body, float friction, float restitution) override;
private:
    ColliderNormal _collider_normal;

    void get_points_from_file(const std::string& path);
};

#endif //COLLIDERS_CHAINCOLLIDER_HPP