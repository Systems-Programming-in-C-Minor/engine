#ifndef COLLIDERS_COLLIDER_HPP
#define COLLIDERS_COLLIDER_HPP
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
    std::vector<GameObject> collision_since_previous_tick();
    void render(IRenderer &renderer, bool is_world_space) const override;

    [[nodiscard]] bool get_ignore_collision_physics() const;
    void set_ignore_collision_physics(bool icp);
};

#endif //COLLIDERS_COLLIDER_HPP