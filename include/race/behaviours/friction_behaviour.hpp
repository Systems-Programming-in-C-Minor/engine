
#ifndef ENGINE_FRICTION_BEHAVIOUR_HPP
#define ENGINE_FRICTION_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"

class FrictionBehaviour : public Component, public ITickable {

private:
    void _friction();

public:
    float traction = 3.6f;
    float max_lateral_impulse = 1.f;
    float drift_friction = 1.6f;
    float angular_friction = 1.6f;
    float drag_modifier = .3f;

    void tick(GameObject &object) override;
};

#endif //ENGINE_FRICTION_BEHAVIOUR_HPP
