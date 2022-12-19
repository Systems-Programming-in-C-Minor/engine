#ifndef GAME_CHECKPOINT_HPP
#define GAME_CHECKPOINT_HPP

#include <gameobject.hpp>
#include "optional"

class Checkpoint : public GameObject {
public:
    Checkpoint(const std::string &name, const std::string &tag, bool is_finish_line,
               std::optional<std::shared_ptr<Checkpoint>> previous_checkpoint);

    const std::optional<std::shared_ptr<Checkpoint>> previous_checkpoint;
    const bool _is_finish_line;
};

#endif //GAME_CHECKPOINT_HPP
