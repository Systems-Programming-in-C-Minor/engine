#include "components/colliders/spritecollider.hpp"

std::string SpriteCollider::get_path(){
    return m_path;
}

void SpriteCollider::set_path(std::string p){
    m_path = p;
}
