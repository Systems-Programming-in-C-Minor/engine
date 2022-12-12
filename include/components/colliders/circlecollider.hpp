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

protected:
    void set_fixture(b2Body& body, float friction, float restitution) override;

public:
    explicit CircleCollider(double radius);

    [[nodiscard]] double get_radius() const;
};

#endif //COLLIDERS_CIRCLECOLLIDER_HPP