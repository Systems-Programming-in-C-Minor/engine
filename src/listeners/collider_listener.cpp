#include "listeners/collider_listener.hpp"

ColliderListener::ColliderListener(EventManager &manager) {
    manager.register_listener(ColliderEntry, [this](const IEvent &event) {
        on_collider_entry(dynamic_cast<const ColliderEntryEvent &>(event));
    });
    manager.register_listener(ColliderExit, [this](const IEvent &event) {
        on_collider_exit(dynamic_cast<const ColliderExitEvent &>(event));
    });
}
