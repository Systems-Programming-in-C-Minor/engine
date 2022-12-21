#include "race/objects/car.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "utils/trigonometry.hpp"
#include "components/colliders/boxcollider.hpp"
#include "race/behaviours/checkpoint_behaviour.hpp"
#include <scene.hpp>

Car::Car(const std::string &name, const std::string &sprite_path, const Vector2d position,
         const std::shared_ptr<Scene> &scene, bool is_enabled)
        : GameObject(name, "car"),
          DriveBehaviour(std::make_shared<RigidBody>(*scene, 1000, BodyType::dynamic_body, position), is_enabled) {


    auto sprite = std::make_shared<Sprite>(sprite_path, 2);
    add_component(sprite);

    auto collider = std::make_shared<BoxCollider>(1.65f, 4.f);
    _body->set_mass(1600.f);
    _body->set_collider(collider);
    add_component(_body);
    transform.set_scale(.5f);
    transform.set_angle(degrees_to_radians(90.f));

    add_component(std::make_shared<FrictionBehaviour>());
    add_component(std::make_shared<CheckpointBehaviour>(scene->get_event_manager()));
}
