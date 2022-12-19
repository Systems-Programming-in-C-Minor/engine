#ifndef COLLIDERS_CIRCLECOLLIDER_HPP
#define COLLIDERS_CIRCLECOLLIDER_HPP

#include "collider.hpp"

/**
 * @brief Collider class for circular objects.
 */
class CircleCollider : public Collider
{
private:
    double _radius;

protected:
    /**
     * @brief Set the collider's fixture.
     * @param body The current b2Body.
     * @param friction desired friction.
     * @param restitution The desired restitution.
     */
    void set_fixture(b2Body& body, float friction, float restitution) override;

public:
    explicit CircleCollider(Vector2d point, float radius);

    /**
     * @brief Get the collider's radius.
     * @return The radius.
     */
    [[nodiscard]] double get_radius() const;
};

#endif //COLLIDERS_CIRCLECOLLIDER_HPP