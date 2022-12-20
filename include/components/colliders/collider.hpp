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
 * @brief The base class for all colliders.
 */
class Collider
{
protected:
    /**
     * @brief The RigidBody friend class.
     */
    friend class RigidBody;

    /**
     * @brief A vector of Vector2d points of the Collider.
     */
    std::vector<Vector2d> _points;

    /**
     * @brief Flag to optionally ignore physics on collision.
     */
    bool _ignore_collision_physics;

    /**
     * @brief Set the fixture of the collider.
     * @param body The current b2Body.
     * @param friction desired friction.
     * @param restitution The desired restitution.
     */
    virtual void set_fixture(b2Body& body, float friction, float restitution) = 0;
};

#endif //COLLIDERS_COLLIDER_HPP