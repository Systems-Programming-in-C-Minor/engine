#include "components/colliders/collider.hpp"

void Collider::render(IRenderer &renderer, bool is_world_space) const {

}

bool Collider::get_ignore_collision_physics() const {
    return _ignore_collision_physics;
}

void Collider::set_ignore_collision_physics(bool icp) {
    _ignore_collision_physics = icp;
}
