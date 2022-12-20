#ifndef GAME_CHECKPOINT_FACTORY_HPP
#define GAME_CHECKPOINT_FACTORY_HPP

#include <optional>
#include "race/objects/checkpoint.hpp"

/**
 * @brief Class used by the Checkpoint factory for an orientation value.
 */
class CheckpointDef {
public:
    /**
     * @brief Constructor.
     * @param position The position of the checkpoint.
     * @param width The width of the checkpoint.
     * @param angle The angle of the checkpoint.
     */
    CheckpointDef(Vector2d position, float width, float angle);

    const Vector2d position;
    const float width;
    const float angle;
};

/**
 * @brief Class representing a Checkpoint factory.
 */
class CheckpointFactory {
public:
    static std::shared_ptr<Checkpoint>
    /**
     * @brief Get method of the checkpoint factory.
     * @param is_finish_line Boolean value whether or not the checkpoint is a finish line.
     * @param previous_checkpoint Optionally the previous checkpoint linked to this one.
     * @param scene The Scene the Checkpoint will be loaded into.
     * @param orientation The orientation of the Checkpoint, as a CheckpointDef object.
     * @return A shared pointer Checkpoint object.
     */
    get(bool is_finish_line, const std::optional<std::shared_ptr<Checkpoint>> &previous_checkpoint,
        const std::shared_ptr<Scene> &scene, CheckpointDef orientation);
};

#endif //GAME_CHECKPOINT_FACTORY_HPP
