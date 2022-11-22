#include "components/colliders/circlecollider.hpp"

double CircleCollider::get_radius() const {
    return _radius;
}
void CircleCollider::set_radius(double r){
    _radius = r;
}
