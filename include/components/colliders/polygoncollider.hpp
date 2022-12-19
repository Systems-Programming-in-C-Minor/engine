#ifndef COLLIDERS_POLYGONCOLLIDER_HPP
#define COLLIDERS_POLYGONCOLLIDER_HPP

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

class PolygonCollider : public Collider
{
public:
    explicit PolygonCollider(std::vector<Vector2d> points, bool ignore_collision_physics = false);
    explicit PolygonCollider(const std::string& path, bool ignore_collision_physics = false);

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
private:
    /**
     * @brief Get points from a given file.
     * @param path The file from which the points will be retrieved.
     */
    void get_points_from_file(const std::string& path);
};

#endif //COLLIDERS_POLYGONCOLLIDER_HPP