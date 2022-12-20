#ifndef GAME_CHECKPOINT_HPP
#define GAME_CHECKPOINT_HPP

#include <gameobject.hpp>
#include "optional"

/**
 * @brief Class representing a Checkpoint object.
 */
class Checkpoint : public GameObject {
public:
    /**
     * @brief Constructor.
     * @param name The name of the checkpoint.
     * @param tag The tag of the checkpoint.
     * @param is_finish_line Boolean value whether or not the checkpoint is a finish line.
     * @param previous_checkpoint Optionally the previous checkpoint linked to this one.
     */
    Checkpoint(const std::string &name, const std::string &tag, bool is_finish_line,
               std::optional<std::shared_ptr<Checkpoint>> previous_checkpoint);

    /**
     * @brief Optionally the previous checkpoint linked to this one.
     */
    const std::optional<std::shared_ptr<Checkpoint>> previous_checkpoint;

    /**
     * @brief Boolean value whether or not the checkpoint is a finish line.
     */
    const bool is_finish_line;
};

#endif //GAME_CHECKPOINT_HPP
