
#ifndef ENGINE_COLLIDER_LISTENER_HPP
#define ENGINE_COLLIDER_LISTENER_HPP

#include "events.hpp"
#include "../include/managers/event_manager.hpp"

class ColliderListener {
protected:
    explicit ColliderListener(EventManager &manager);

public:
    virtual void on_collider_entry(const ColliderEntryEvent &event) = 0;

    virtual void on_collider_exit(const ColliderExitEvent &event) = 0;

};

#endif //ENGINE_COLLIDER_LISTENER_HPP
