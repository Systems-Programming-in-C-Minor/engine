
#ifndef ENGINE_CARBEHAVIOUR_HPP
#define ENGINE_CARBEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"

class CarBehaviour : public Component, public ITickable {

private:
    void friction();

    void drive(float desired_speed);

    void turn(float steering);

protected:

    void drive_forwards();

    void drive_backwards();

    void turn_left();

    void turn_right();

public:
    float max_speed_forwards = 4.f;
    float max_speed_backwards = -2.f;
    float max_drive_force = 3.8f;
    float current_traction = 1.f;
    float max_lateral_impulse = 1.f;
    float drift_friction = 1.f;
    float angular_friction = 1.f;
    float drag_modifier = 8.f;
    float steering_impulse = 20.f;

    void tick(GameObject &object) override;
};

#endif //ENGINE_CARBEHAVIOUR_HPP
