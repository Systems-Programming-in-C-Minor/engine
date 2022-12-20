#include "listeners/ai_listener.hpp"

AIListener::AIListener(EventManager &manager) {
    manager.register_listener(AITargetReached, [this](const IEvent &event) {
        on_target_reached(dynamic_cast<const AITargetReachedEvent &>(event));
    });
}