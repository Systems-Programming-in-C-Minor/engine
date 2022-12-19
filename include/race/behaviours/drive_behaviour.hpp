
#ifndef ENGINE_CARBEHAVIOUR_HPP
#define ENGINE_CARBEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"

class RigidBody;

class DriveBehaviour {

private:

    void _drive(float desired_speed);

    void _turn(float steering);

    RigidBody &_body;

protected:
    explicit DriveBehaviour(RigidBody &body);

public:
    void turn(float amount = 1.0f);

    void drive_forwards(float amount = 1.0f);

    void drive_backwards(float amount = 1.0f);

    void turn_left(float amount = 1.0f);

    void turn_right(float amount = 1.0f);

    void brake();


    float max_speed_forwards = 2030.f;
    float max_speed_backwards = -1200.f;
    float max_drive_force = 800.f;
    float drive_traction = 3.6f;
    float steering_impulse = 60.f;
};

#endif //ENGINE_CARBEHAVIOUR_HPP
