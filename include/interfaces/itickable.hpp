#ifndef ENGINE_ITICKABLE_HPP
#define ENGINE_ITICKABLE_HPP

#include "gameobject.hpp"

class ITickable {
public:
    virtual void tick(GameObject &object) = 0;
};

#endif //ENGINE_ITICKABLE_HPP
