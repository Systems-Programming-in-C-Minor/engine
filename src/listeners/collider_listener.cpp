#include "../include/listeners/collider_listener.hpp"
#include "../include/global.hpp"

ColliderListener::ColliderListener(EventManager manager) {
    manager.register_listener(ColliderEntry, &ColliderListener::on_collider_entry)
}
