
#ifndef ENGINE_CARBEHAVIOUR_HPP
#define ENGINE_CARBEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"

class CarBehaviour : public Component, public ITickable {

private:
    void _friction();

    void _drive(float desired_speed);

    void _turn(float steering);

protected:
    void turn(float amount = 1.0f);

    void drive_forwards(float amount = 1.0f);

    void drive_backwards(float amount = 1.0f);

    void turn_left(float amount = 1.0f);

    void turn_right(float amount = 1.0f);

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
