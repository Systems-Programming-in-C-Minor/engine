#ifndef COLLIDERS_CIRCLECOLLIDER_HPP
#define COLLIDERS_CIRCLECOLLIDER_HPP

#include "collider.hpp"

/**
 * Collider class for circular objects
 */
class CircleCollider : public Collider
{
private:
    double _radius;

public:
    explicit CircleCollider(double radius);

    [[nodiscard]] double get_radius() const;
};

#endif //COLLIDERS_CIRCLECOLLIDER_HPP