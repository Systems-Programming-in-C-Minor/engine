#ifndef ENGINE_ITICKABLE_HPP
#define ENGINE_ITICKABLE_HPP

class GameObject;

class ITickable {
public:
    virtual void tick(GameObject &object) = 0;
    virtual ~ITickable() = default;
};

#endif //ENGINE_ITICKABLE_HPP
