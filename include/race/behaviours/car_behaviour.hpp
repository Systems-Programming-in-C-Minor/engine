
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

    void brake();

public:
    float max_speed_forwards = 5600.f;
    float max_speed_backwards = -1200.f;
    float max_drive_force = 800.f;
    float current_traction = 3.6f;
    float max_lateral_impulse = 1.f;
    float drift_friction = 1.6f;
    float angular_friction = 1.6f;
    float drag_modifier = 1.f;
    float steering_impulse = 60.f;

    void tick(GameObject &object) override;
};

#endif //ENGINE_CARBEHAVIOUR_HPP
