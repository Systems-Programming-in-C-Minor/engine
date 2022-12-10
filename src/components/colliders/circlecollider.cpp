#include "components/colliders/circlecollider.hpp"

CircleCollider::CircleCollider(double radius) : _radius(radius) {}

double CircleCollider::get_radius() const {
    return _radius;
}

void CircleCollider::set_fixture(b2Body& body, float friction, float restitution) {
    /**
     * TODO Task: Connect a b2CircleCollider to a CircleCollider
     * https://app.clickup.com/t/34xa59g
     */
}