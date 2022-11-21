#pragma once
#include "gameobject.hpp"
#include "render/irenderer.hpp"
#include <vector>
#include "render/itexture.hpp"

class IRenderer;

class Collider : public Component, public IRenderable
{
private:
    bool _ignore_collision_physics = false;

public:
    Collider() {};
    ~Collider() = default;

    std::vector<GameObject> collision_since_previous_tick();
    void render(IRenderer &renderer, bool is_world_space) const override;

    bool get_ignore_collision_physics();
    void set_ignore_collision_physics(bool icp);
};
