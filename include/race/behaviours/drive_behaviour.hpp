
#ifndef ENGINE_DRIVE_BEHAVIOUR_HPP
#define ENGINE_DRIVE_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"
#include <memory>

class RigidBody;

/**
 * @brief Class which defines drive behaviour.
 */
class DriveBehaviour {

private:
    /**
     * @brief The private drive method of the behavior.
     * @param desired_speed The speed at which will be driven.
     */
    void _drive(float desired_speed);

    /**
     * @brief The private turn method of the behavior.
     * @param steering The angle of the steering.
     */
    void _turn(float steering);


protected:
    /**
     * @brief Explicit constructor.
     * @param body The RigidBody of the behaviour.
     * @param is_enabled Whether or not the behaviour is enabled.
     */
    explicit DriveBehaviour(std::shared_ptr<RigidBody> body, bool is_enabled = true);

    std::shared_ptr<RigidBody> _body;

public:
    /**
     * @brief The turn method of the behavior.
     * @param amount The float value how much will be turned.
     */
    void turn(float amount = 1.0f);

    /**
     * @brief The forward drive method of the behavior.
     * @param amount The float value how much will be driven forward.
     */
    void drive_forwards(float amount = 1.0f);

    /**
     * @brief The backwards drive method of the behavior.
     * @param amount The float value how much will be driven backwards.
     */
    void drive_backwards(float amount = 1.0f);

    /**
     * @brief The turn left method of the behavior.
     * @param amount The float value how much will be turned left.
     */
    void turn_left(float amount = 1.0f);

    /**
     * @brief The turn right method of the behavior.
     * @param amount The float value how much will be turned right.
     */
    void turn_right(float amount = 1.0f);

    /**
     * @brief The break method of the behavior.
     */
    void brake();

    /**
     * @brief The max speed forwards.
     */
    float max_speed_forwards = 2030.f;

    /**
     * @brief The max speed backwards.
     */
    float max_speed_backwards = -1200.f;

    /**
     * @brief The max amount of applied force.
     */
    float max_drive_force = 800.f;

    /**
     * @brief The max amount of applied traction.
     */
    float drive_traction = 3.6f;

    /**
     * @brief The max amount of steering impulse.
     */
    float steering_impulse = 60.f;

    /**
     * @brief Whether or not the object is enabled.
     * @details If the object is not enabled, it will not drive.
     */
    bool is_enabled;
};

#endif //ENGINE_DRIVE_BEHAVIOUR_HPP
