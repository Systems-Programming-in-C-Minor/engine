#include "components/colliders/spritecollider.hpp"
SpriteCollider::SpriteCollider(std::string path) {
    _path = path;
}

std::string SpriteCollider::get_path(){
    return _path;
}

void SpriteCollider::set_path(std::string p){
    _path = p;
}
