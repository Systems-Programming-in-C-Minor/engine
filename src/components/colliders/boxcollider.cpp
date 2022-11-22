#include "components/colliders/boxcollider.hpp"

double BoxCollider::get_width() const {
    return _width;
}

void BoxCollider::set_width(double w){
    _width = w;
}
double BoxCollider::get_height() const {
    return _height;
}
void BoxCollider::set_height(double h){
    _height = h;
}
