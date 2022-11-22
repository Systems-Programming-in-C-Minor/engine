#ifndef COLLIDERS_CIRCLECOLLIDER_HPP
#define COLLIDERS_CIRCLECOLLIDER_HPP

#include "collider.hpp"

class CircleCollider : public Collider
{
private:
    double _radius;

public:
    [[nodiscard]] double get_radius() const;
    void set_radius(double r);
};

#endif //COLLIDERS_CIRCLECOLLIDER_HPP