//
// Created by Laerositus on 11/11/2022.
//

#include "components/colliders/SpriteCollider.hpp"

std::string SpriteCollider::get_path(){
    return m_path;
}

void SpriteCollider::set_path(std::string p){
    m_path = p;
}