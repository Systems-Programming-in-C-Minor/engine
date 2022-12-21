#include "race/factories/checkpoint_factory.hpp"
#include "race/objects/checkpoint.hpp"
#include "components/colliders/boxcollider.hpp"
#include "utils/trigonometry.hpp"

std::shared_ptr<Checkpoint>
CheckpointFactory::get(bool is_finish_line, const std::optional<std::shared_ptr<Checkpoint>> &previous_checkpoint,
                       const std::shared_ptr<Scene> &scene, CheckpointDef orientation) {

    const auto collider = std::make_shared<BoxCollider>(orientation.width, .2f, true);
    const auto body = std::make_shared<RigidBody>(*scene, 2, BodyType::static_body, orientation.position);
    body->set_collider(collider);
    body->set_angle(degrees_to_radians(orientation.angle));

    auto name = "checkpoint" +
                std::to_string(orientation.position.x).substr(0, std::to_string(orientation.position.x).find('.') + 2) +
                "_" +
                std::to_string(orientation.position.y).substr(0, std::to_string(orientation.position.y).find('.') + 2);

    auto checkpoint = std::make_shared<Checkpoint>(name, "checkpoint", is_finish_line, previous_checkpoint);
    checkpoint->add_component(body);

    return checkpoint;
}

CheckpointDef::CheckpointDef(Vector2d position, float width, float angle) :
        position(position), width(width), angle(angle) {}
