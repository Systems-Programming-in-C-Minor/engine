#ifndef ENGINE_ITICKABLE_HPP
#define ENGINE_ITICKABLE_HPP

class GameObject;

class ITickable {

    virtual void tick(GameObject &object) const = 0;

};

#endif //ENGINE_ITICKABLE_HPP
