#include "components/colliders/boxcollider.hpp"

double BoxCollider::get_width(){
    return _width;
}

void BoxCollider::set_width(double w){
    _width = w;
}
double BoxCollider::get_height(){
    return _height;
}
void BoxCollider::set_height(double h){
    _height = h;
}
