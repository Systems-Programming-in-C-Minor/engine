
#ifndef ENGINE_FRICTION_BEHAVIOUR_HPP
#define ENGINE_FRICTION_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"

/**
 * @brief Class which defines friction behaviour.
 */
class FrictionBehaviour : public Component, public ITickable {

private:
    /**
     * @brief The friction method of the behaviour.
     */
    void _friction();

public:
    float traction = 3.6f;
    float max_lateral_impulse = 1.f;
    float drift_friction = 1.6f;
    float angular_friction = 1.6f;
    float drag_modifier = .3f;

    /**
     * @brief Method will run every tick.
     * @param object the GameObject on which the action is performed.
     */
    void tick(GameObject &object) override;
};

#endif //ENGINE_FRICTION_BEHAVIOUR_HPP
