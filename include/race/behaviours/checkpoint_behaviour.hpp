#ifndef GAME_CHECKPOINT_BEHAVIOUR_HPP
#define GAME_CHECKPOINT_BEHAVIOUR_HPP

#include <components/component.hpp>
#include "listeners/collider_listener.hpp"
#include <optional>

class Checkpoint;

class CheckpointBehaviour : public Component, public ColliderListener {
public:
    explicit CheckpointBehaviour(EventManager &event_manager);

    void on_collider_entry(const ColliderEntryEvent &event) override;

    [[nodiscard]] int get_number_of_laps() const;

    [[nodiscard]] std::vector<long> get_lap_times() const;

    [[nodiscard]] std::optional<std::shared_ptr<Checkpoint>> get_last_touched() const;

private:
    std::optional<std::shared_ptr<Checkpoint>> _last_touched = std::nullopt;
    std::optional<std::shared_ptr<Checkpoint>> _reached = std::nullopt;

    std::vector<long> _lap_times;

    void check_and_set_checkpoint(GameObject *game_object);
};

#endif //GAME_CHECKPOINT_BEHAVIOUR_HPP
