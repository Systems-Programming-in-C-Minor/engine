#ifndef RACE_AI_BEHAVIOUR_HPP
#define RACE_AI_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"
#include "drive_behaviour.hpp"
#include "vector2d.hpp"
#include "friction_behaviour.hpp"
#include <memory>

class GameObject;

/**
 * @brief Class which defines AI behaviour.
 */
class AIBehaviour : public Component, public ITickable {

private:
    std::shared_ptr<GameObject> _target;
    bool reached_target = false;
    float _offset = 2.5f;

    /**
     * @brief Method which lets an AI object move to the defined _target value.
     */
    void move_to_target();
public:
    /**
     * @brief Distance within the AI object will have reached the target (meters).
     */
    float reached_target_distance = 8.f;

    /**
     * @brief If the target is this far behind, the AI object will turn around to reach the target (meters).
     */
    float reverse_distance = 30.f;

    /**
     * @brief If this angle is reached, the AI object will turn left or right to reach the target (meters).
     */
    float max_angle_to_direction = 0.08f;

    /**
     * @brief Explicit constructor.
     * @param target The target the AI object will move to.
     */
    explicit AIBehaviour(std::shared_ptr<GameObject> target = {});

    /**
     * @brief Virtual destructor.
     */
    ~AIBehaviour() override;

    /**
     * @brief Setter method for the _target value of the AI object.
     * @param game_object A shared pointer to the GameObject which will become the _target.
     */
    void set_target(std::shared_ptr<GameObject> game_object);

    /**
     * @brief Getter method for the _offset value used for randomization of the AI
     * @return Offset value in meters
     */
     [[nodiscard]] float get_offset() const;

    /**
    * @brief Getter method for the _offset value used for randomization of the AI
     * @param offset in meters from the original position of the target
    */
     void set_offset(float offset);

    /**
     * @brief Method runs every tick.
     * @param object the GameObject on which the action is performed.
     */
    void tick(GameObject &object) override;
};

#endif //RACE_AI_BEHAVIOUR_HPP