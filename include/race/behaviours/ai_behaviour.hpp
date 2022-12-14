#include "interfaces/itickable.hpp"
#include "components/component.hpp"
#include "car_behaviour.hpp"
#include "vector2d.hpp"
#include <memory>

class GameObject;

class AIBehaviour : public CarBehaviour {

private:
    std::shared_ptr<GameObject> _target;

public:

    virtual ~AIBehaviour();

    float reached_target_distance = 1.f;
    float stopping_distance = 5.f;
    float stopping_speed = 50.f;
    float reverse_distance = 25.f;

    float turn_speed = 32.f;
    float forward_speed = 10.f;

    bool reached_target = false;

    void set_target(std::shared_ptr<GameObject> game_object);

    void move_to_target();
    void tick(GameObject &object) override;
};