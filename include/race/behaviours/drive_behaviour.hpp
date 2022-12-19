
#ifndef ENGINE_DRIVE_BEHAVIOUR_HPP
#define ENGINE_DRIVE_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"
#include <memory>

class RigidBody;

class DriveBehaviour {

private:

    void _drive(float desired_speed);

    void _turn(float steering);


protected:
    explicit DriveBehaviour(std::shared_ptr<RigidBody> body);

    std::shared_ptr<RigidBody> _body;

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

#endif //ENGINE_DRIVE_BEHAVIOUR_HPP
