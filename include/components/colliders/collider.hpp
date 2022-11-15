#pragma once
#include "GameObject.hpp"

#include <vector>

class IRenderer;

class Collider : public Component
{
    Collider();
    ~Collider();

    bool m_ignore_collision_physics;

public:
    std::vector<GameObject> collision_since_previous_tick();
//    void render(IRenderer renderer);

    bool get_ignore_collision_physics();
    void set_ignore_collision_physics(bool icp);
};
