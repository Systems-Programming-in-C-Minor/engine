#include "components/colliders/spritecollider.hpp"

std::string SpriteCollider::get_path(){
    return _path;
}

void SpriteCollider::set_path(std::string p){
    _path = p;
}
