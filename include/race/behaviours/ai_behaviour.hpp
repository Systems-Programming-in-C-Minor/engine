#ifndef RACE_AI_BEHAVIOUR_HPP
#define RACE_AI_BEHAVIOUR_HPP

#include "interfaces/itickable.hpp"
#include "components/component.hpp"
#include "car_behaviour.hpp"
#include "vector2d.hpp"
#include <memory>

class GameObject;

class AIBehaviour : public CarBehaviour {

private:
    std::shared_ptr<GameObject> _target;
    bool reached_target = false;

    void move_to_target();
public:
    ~AIBehaviour() override;

    float reached_target_distance = 5.f;

    void set_target(std::shared_ptr<GameObject> game_object);

    void tick(GameObject &object) override;
};

#endif //RACE_AI_BEHAVIOUR_HPP