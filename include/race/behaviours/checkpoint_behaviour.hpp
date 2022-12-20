#ifndef GAME_CHECKPOINT_BEHAVIOUR_HPP
#define GAME_CHECKPOINT_BEHAVIOUR_HPP

#include <components/component.hpp>
#include "listeners/collider_listener.hpp"
#include <optional>

class Checkpoint;

/**
 * @brief Class which defines Checkpoint behaviour.
 */
class CheckpointBehaviour : public Component, public ColliderListener {
public:
    /**
     * @brief Explicit constructor.
     * @param event_manager The EventManager the behaviour will use to send and receive events.
     */
    explicit CheckpointBehaviour(EventManager &event_manager);

    /**
     * @brief Method which gets called on collider entry.
     * @param The received ColliderEntryEvent.
     */
    void on_collider_entry(const ColliderEntryEvent &event) override;

    /**
     * @brief Getter method for the number of laps.
     * @return Integer value of the number of laps.
     */
    [[nodiscard]] int get_number_of_laps() const;

    /**
     * @brief Getter method for lap times.
     * @return Vector containing long values of all known lap times.
     */
    [[nodiscard]] std::vector<long> get_lap_times() const;

    /**
     * @brief Getter method for the last touched Checkpoint.
     * @return Optionally a shared pointer to the Checkpoint which was touched last.
     */
    [[nodiscard]] std::optional<std::shared_ptr<Checkpoint>> get_last_touched() const;

private:
    std::optional<std::shared_ptr<Checkpoint>> _last_touched = std::nullopt;
    std::optional<std::shared_ptr<Checkpoint>> _reached = std::nullopt;

    std::vector<long> _lap_times;

    /**
     * @brief Creational method for a new Checkpoint.
     * @param game_object The GameObject which will be used as the potential Checkpoint.
     */
    void check_and_set_checkpoint(GameObject *game_object);
};

#endif //GAME_CHECKPOINT_BEHAVIOUR_HPP
