#include "listeners/checkpoint_listener.hpp"

CheckpointListener::CheckpointListener(EventManager &manager) {
    manager.register_listener(CheckpointTouched, [this](const IEvent &event) {
        on_checkpoint_touched(dynamic_cast<const CheckpointTouchedEvent &>(event));
    });
    manager.register_listener(CheckpointReached, [this](const IEvent &event) {
        on_checkpoint_reached(dynamic_cast<const CheckpointReachedEvent &>(event));
    });
    manager.register_listener(CheckpointLapped, [this](const IEvent &event) {
        on_checkpoint_lapped(dynamic_cast<const CheckpointLappedEvent &>(event));
    });
}
