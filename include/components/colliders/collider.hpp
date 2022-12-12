#ifndef COLLIDERS_COLLIDER_HPP
#define COLLIDERS_COLLIDER_HPP
#include "gameobject.hpp"
#include "render/irenderer.hpp"
#include <vector>
#include "render/itexture.hpp"

class IRenderer;
class b2Shape;
class RigidBody;

/**
 * Component class for colliders
 */
class Collider : public Component, public IRenderable
{
protected:
    friend class RigidBody;

    std::vector<Vector2d> _points;
    bool _ignore_collision_physics;

    virtual void set_fixture(b2Body& body, float friction, float restitution) = 0;
public:
    void render(bool is_world_space) const override;
};

#endif //COLLIDERS_COLLIDER_HPP