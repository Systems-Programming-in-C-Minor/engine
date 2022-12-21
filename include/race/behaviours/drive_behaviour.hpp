
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
    void turn(float amount);

    /**
     * @brief The private drive method of the behavior.
     * @param amount The force at which will be driven.
     */
    void drive(float amount);

    /**
     * @brief The break method of the behavior.
     */
    void brake(float amount = 1.0f);

    /**
     * @brief Whether or not the object is enabled.
     * @details If the object is not enabled, it will not drive.
     */
    bool is_enabled;
};

#endif //ENGINE_DRIVE_BEHAVIOUR_HPP
