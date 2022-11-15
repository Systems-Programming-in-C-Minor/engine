#include "components/colliders/collider.hpp"

std::vector<GameObject> Collider::collision_since_previous_tick(){
    std::vector<GameObject> collisions;

    return collisions;
}

//void Collider::render(IRenderer renderer){
//
//}

bool Collider::get_ignore_collision_physics() {
    return m_ignore_collision_physics;
}

void Collider::set_ignore_collision_physics(bool icp) {
    m_ignore_collision_physics = icp;
}
