#include "components/colliders/circlecollider.hpp"

CircleCollider::CircleCollider(double radius) : _radius(radius) {}

double CircleCollider::get_radius() const {
    return _radius;
}
void CircleCollider::set_radius(double r){
    _radius = r;
}
