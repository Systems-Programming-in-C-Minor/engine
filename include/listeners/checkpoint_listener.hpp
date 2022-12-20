
#ifndef ENGINE_CHECKPOINT_LISTENER_HPP
#define ENGINE_CHECKPOINT_LISTENER_HPP

#include "events.hpp"
#include "../include/managers/event_manager.hpp"

/**
 * @brief Interface for objects wanting to respond to checkpoint events.
 */
class CheckpointListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param manager The manager which registers listeners and notifies subscribers.
     */
    explicit CheckpointListener(EventManager &manager);

public:
    /**
     * @brief Called whenever a checkpoint is touched.
     * @param event The desired CheckpointTouchedEvent.
     */
    virtual void on_checkpoint_touched(const CheckpointTouchedEvent &event) {};

    /**
     * @brief Called whenever a checkpoint is reached.
     * @param event The desired CheckpointReachedEvent.
     */
    virtual void on_checkpoint_reached(const CheckpointReachedEvent &event) {};

    /**
     * @brief Called whenever a checkpoint is lapped.
     * @param event The desired CheckpointLappedEvent.
     */
    virtual void on_checkpoint_lapped(const CheckpointLappedEvent &event) {};

};

#endif //ENGINE_CHECKPOINT_LISTENER_HPP
