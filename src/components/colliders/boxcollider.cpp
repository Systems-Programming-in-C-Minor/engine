#include "components/colliders/boxcollider.hpp"

double BoxCollider::get_width(){
    return m_width;
}
void BoxCollider::set_width(double w){
    m_width = w;
}
double BoxCollider::get_height(){
    return m_height;
}
void BoxCollider::set_height(double h){
    m_height = h;
}
