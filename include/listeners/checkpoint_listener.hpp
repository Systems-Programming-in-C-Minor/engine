
#ifndef ENGINE_CHECKPOINT_LISTENER_HPP
#define ENGINE_CHECKPOINT_LISTENER_HPP

#include "events.hpp"
#include "../include/managers/event_manager.hpp"

class CheckpointListener {
protected:
    explicit CheckpointListener(EventManager &manager);

public:
    virtual void on_checkpoint_touched(const CheckpointTouchedEvent &event) {};

    virtual void on_checkpoint_reached(const CheckpointReachedEvent &event) {};

    virtual void on_checkpoint_lapped(const CheckpointLappedEvent &event) {};

};

#endif //ENGINE_CHECKPOINT_LISTENER_HPP
