
#ifndef ENGINE_FRICTION_BEHAVIOUR_HPP
#define ENGINE_FRICTION_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"

/**
 * @brief Class which defines friction behaviour.
 */
class FrictionBehaviour : public Component, public ITickable {
public:
    /**
     * @brief Method will run every tick.
     * @param object the GameObject on which the action is performed.
     */
    void tick(GameObject &object) override;
};

#endif //ENGINE_FRICTION_BEHAVIOUR_HPP
