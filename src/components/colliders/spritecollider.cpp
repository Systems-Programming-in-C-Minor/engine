#include "components/colliders/spritecollider.hpp"
SpriteCollider::SpriteCollider(std::string path) {
    _path = std::move(path);
}

std::string SpriteCollider::get_path() const {
    return _path;
}

void SpriteCollider::set_path(std::string p){
    _path = p;
}
