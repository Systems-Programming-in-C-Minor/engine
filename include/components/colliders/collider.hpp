#pragma once
#include "gameobject.hpp"

#include <vector>

class IRenderer;

class Collider : public Component
{
private:
    bool _ignore_collision_physics;

public:
    Collider();
    ~Collider();

    std::vector<GameObject> collision_since_previous_tick();
//    void render(IRenderer renderer);

    bool get_ignore_collision_physics();
    void set_ignore_collision_physics(bool icp);
};
