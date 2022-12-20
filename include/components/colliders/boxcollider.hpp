#ifndef COLLIDERS_BOXCOLLIDER_HPP
#define COLLIDERS_BOXCOLLIDER_HPP

#include "polygoncollider.hpp"

/**
 * @brief Collider class for rectangular objects.
 */
class BoxCollider : public PolygonCollider
{
private:
    float _width;
    float _height;

public:
    /**
     * @brief Constructor.
     * @param width The width of the collider.
     * @param height The height of the collider.
     * @param ignore_collision_physics An optional flag to ignore collision physics.
     */
    BoxCollider(float width, float height, bool ignore_collision_physics = false);

    /**
     * @brief The collider's width.
     * @return The current width.
     */
    [[nodiscard]] float get_width() const;

    /**
     * @brief The collider's height.
     * @return The current height.
     */
    [[nodiscard]] float get_height() const;

protected:
    [[nodiscard]] std::vector<Vector2d> get_vertices(b2Body& body, const Transform& transform) const override;
};

#endif //COLLIDERS_BOXCOLLIDER_HPP