#ifndef ENGINE_ITICKABLE_HPP
#define ENGINE_ITICKABLE_HPP

class GameObject;

/**
 * @brief Interface for objects which are tickable.
 */
class ITickable {
public:
    /**
     * @brief Method which gets called every tick.
     *        Override for implementing the desired behaviour.
     * @param object the GameObject on which the action is performed.
     * */
    virtual void tick(GameObject &object) = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~ITickable() = default;
};

#endif //ENGINE_ITICKABLE_HPP
