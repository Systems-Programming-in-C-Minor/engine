//
// Created by lars on 13-11-22.
//

#ifndef ENGINE_ITICKABLE_HPP
#define ENGINE_ITICKABLE_HPP

class GameObject;

class ITickable {

    virtual void tick(GameObject &object) const = 0;

};

#endif //ENGINE_ITICKABLE_HPP
