#include "components/colliders/boxcollider.hpp"

BoxCollider::BoxCollider(double width, double height) : Collider(), _width(width), _height(height) {}

double BoxCollider::get_width() const {
    return _width;
}

double BoxCollider::get_height() const {
    return _height;
}
