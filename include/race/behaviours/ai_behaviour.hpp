#ifndef RACE_AI_BEHAVIOUR_HPP
#define RACE_AI_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"
#include "drive_behaviour.hpp"
#include "vector2d.hpp"
#include "friction_behaviour.hpp"
#include <memory>

class GameObject;

class AIBehaviour : public Component, public DriveBehaviour, public ITickable {

private:
    std::shared_ptr<GameObject> _target;
    bool reached_target = false;

    void move_to_target();
public:
    explicit AIBehaviour(std::shared_ptr<RigidBody> body, std::shared_ptr<GameObject> target);
    explicit AIBehaviour(std::shared_ptr<RigidBody> body);
    ~AIBehaviour() override;

    float reached_target_distance = 5.f;
    float reverse_distance = 25.f;
    float max_angle_to_direction = 0.08f;

    void set_target(std::shared_ptr<GameObject> game_object);

    void tick(GameObject &object) override;
};

#endif //RACE_AI_BEHAVIOUR_HPP