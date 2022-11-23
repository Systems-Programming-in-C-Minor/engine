#include "components/colliders/circlecollider.hpp"

CircleCollider::CircleCollider(double radius) : _radius(radius) {}

double CircleCollider::get_radius() const {
    return _radius;
}

