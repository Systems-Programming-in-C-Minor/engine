
#ifndef ENGINE_COLLIDER_LISTENER_HPP
#define ENGINE_COLLIDER_LISTENER_HPP

#include "events.hpp"
#include "../include/managers/event_manager.hpp"

/**
 * @brief Interface for objects wanting to respond to collider events.
 */
class ColliderListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param manager The manager which registers listeners and notifies subscribers.
     */
    explicit ColliderListener(EventManager &manager);

public:
    /**
     * @brief This method will be called whenever an object enters a collider.
     *        Override for implementing the desired behaviour.
     * @param event The desired ColliderEntryEvent.
     */
    virtual void on_collider_entry(const ColliderEntryEvent &event) {};

    /**
     * @brief This method will be called whenever an object leaves a collider.
     *        Override for implementing the desired behaviour.
     * @param event The desired ColliderExitEvent.
     */
    virtual void on_collider_exit(const ColliderExitEvent &event) = 0;

};

#endif //ENGINE_COLLIDER_LISTENER_HPP
