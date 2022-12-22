
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
     * @brief The max reached lateral impulse.
     * @details If exceeded, this is the level the lateral impulse will return to.
     */
    float max_lateral_impulse = 1.f;

    /**
     * @brief The amount of drift friction which will be applied.
     */
    float drift_friction = 3.2f;

    /**
     * @brief The amount of angular friction which will be applied.
     */
    float angular_friction = 1.6f;

    /**
     * @brief The amount of drag to apply.
     */
    float drag_modifier = .28f;

    /**
     * @brief Method will run every tick.
     * @param object the GameObject on which the action is performed.
     */
    void tick(GameObject &object) override;
};

#endif //ENGINE_FRICTION_BEHAVIOUR_HPP
