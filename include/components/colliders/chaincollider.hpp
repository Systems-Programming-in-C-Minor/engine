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
 * @brief Collider class for polygonal objects.
 */
class ChainCollider : public Collider
{
public:
    /**
     * @brief Explicit constructor.
     * @param points The points of the collider in a Vector2D vector.
     * @param ignore_collision_physics An optional flag to ignore collision physics.
     * @param collider_normal An enum which defines the direction of the collider.
     */
    explicit ChainCollider(std::vector<Vector2d> points, bool ignore_collision_physics = false, ColliderNormal collider_normal = ColliderNormal::outwards);\

    /**
     * @brief Explicit constructor.
     * @param path The path from which the collider is loaded.
     * @param ignore_collision_physics An optional flag to ignore collision physics.
     * @param collider_normal An enum which defines the direction of the collider.
     */
    explicit ChainCollider(const std::string& path, bool ignore_collision_physics = false, ColliderNormal collider_normal = ColliderNormal::outwards);

    /**
     * @brief The collider's points.
     * @return The current points.
     */
    [[nodiscard]] std::vector<Vector2d> get_points() const;

protected:
    /**
     * @brief Set the collider's fixture.
     * @param body The current b2Body.
     * @param friction desired friction.
     * @param restitution The desired restitution.
     */
    void set_fixture(b2Body& body, float friction, float restitution) override;
    [[nodiscard]] std::vector<Vector2d> get_vertices(b2Body& body, const Transform& transform) const override;
private:
    ColliderNormal _collider_normal;

    /**
     * @brief Get points from a given file.
     * @param path The file from which the points will be retrieved.
     */
    void get_points_from_file(const std::string& path);
};

#endif //COLLIDERS_CHAINCOLLIDER_HPP