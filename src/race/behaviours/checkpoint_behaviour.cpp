#include "race/behaviours/checkpoint_behaviour.hpp"
#include "race/objects/checkpoint.hpp"
#include "global.hpp"
#include <gameobject.hpp>

CheckpointBehaviour::CheckpointBehaviour(EventManager &event_manager) : ColliderListener(event_manager) {}

void CheckpointBehaviour::on_collider_entry(const ColliderEntryEvent &event) {
    if (event.collider_a->game_object == game_object) {
        check_and_set_checkpoint(event.collider_b->game_object);
        return;
    }
    if (event.collider_b->game_object == game_object) {
        check_and_set_checkpoint(event.collider_a->game_object);
        return;
    }
}

void CheckpointBehaviour::on_collider_exit(const ColliderExitEvent &event) {}

void CheckpointBehaviour::check_and_set_checkpoint(GameObject *game_object) {
    if (game_object->get_tag() != "checkpoint")
        return;

    auto checkpoint = reinterpret_cast<Checkpoint *>(game_object);

    auto first_checkpoint = !checkpoint->previous_checkpoint.has_value() && !_reached.has_value();
    auto new_checkpoint = checkpoint->previous_checkpoint.has_value() && _reached.has_value() &&
                          checkpoint->previous_checkpoint.value()->get_name() == _reached.value()->get_name();

    if (checkpoint->_is_finish_line && new_checkpoint) {
        _reached = std::nullopt;
        const auto now = std::chrono::system_clock::now();
        const auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
        _lap_times.emplace_back(value.count());
        return;
    }

    if (new_checkpoint || first_checkpoint)
        _reached = std::make_shared<Checkpoint>(*checkpoint);
}

int CheckpointBehaviour::get_laps() const {
    return (int) _lap_times.size();
}

std::vector<long> CheckpointBehaviour::get_lap_times() const {
    return _lap_times;
}
