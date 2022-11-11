//
// Created by Laerositus on 11/11/2022.
//

#include "components/colliders/CircleCollider.hpp"

double CircleCollider::get_radius(){
    return m_radius;
}
void CircleCollider::set_radius(double r){
    m_radius = r;
}