
#ifndef ENGINE_COLLISION_HANDLER_HPP
#define ENGINE_COLLISION_HANDLER_HPP

#include "box2d/box2d.h"

class CollisionHandler : public b2ContactListener {
public:
    void BeginContact(b2Contact *contact) override;

    void EndContact(b2Contact *contact) override;
};

#endif //ENGINE_COLLISION_HANDLER_HPP
