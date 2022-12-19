#include "race/objects/checkpoint.hpp"
#include <optional>
#include <utility>

Checkpoint::Checkpoint(const std::string &name, const std::string &tag, const bool is_finish_line,
                       std::optional<std::shared_ptr<Checkpoint>> previous_checkpoint) :
        GameObject(name, tag),
        _is_finish_line(is_finish_line),
        previous_checkpoint(std::move(previous_checkpoint)) {}
