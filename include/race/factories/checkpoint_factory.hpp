#ifndef GAME_CHECKPOINT_FACTORY_HPP
#define GAME_CHECKPOINT_FACTORY_HPP

#include <optional>
#include "race/objects/checkpoint.hpp"

class CheckpointDef {
public:
    CheckpointDef(Vector2d position, float width, float angle);

    const Vector2d position;
    const float width;
    const float angle;
};

class CheckpointFactory {
public:
    static std::shared_ptr<Checkpoint>
    get(bool is_finish_line, const std::optional<std::shared_ptr<Checkpoint>> &previous_checkpoint,
        const std::shared_ptr<Scene> &scene, CheckpointDef orientation);
};

#endif //GAME_CHECKPOINT_FACTORY_HPP
