#ifndef ENGINE_MULTIPLAYER_LISTENER_HPP
#define ENGINE_MULTIPLAYER_LISTENER_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

/**
 * @brief Interface for objects wanting to respond to ui object events.
 */
class MultiplayerListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param event_manager The manager which registers listeners and notifies subscribers.
     */
    explicit MultiplayerListener(EventManager &event_manager);

public:
    /**
     * @brief Called whenever a ui object is pressed.
     * @param event The desired UserJoinedMultiplayerEvent.
     */
    virtual void on_user_join(const UserJoinedMultiplayerEvent &event) {}

    /**
     * @brief Called whenever a ui object is pressed.
     * @param event The desired UserLeftMultiplayerEvent.
     */
    virtual void on_user_leave(const UserLeftMultiplayerEvent &event) {}

    /**
     * @brief Called whenever a ui object is pressed.
     * @param event The desired AllocationMultiplayerEvent.
     */
    virtual void on_allocation(const AllocationMultiplayerEvent &event) {}

    /**
     * @brief Called whenever a ui object is pressed.
     * @param event The desired UsersMultiplayerEvent.
     */
    virtual void on_users(const UsersMultiplayerEvent &event) {}

    /**
     * @brief Called whenever a ui object is pressed.
     * @param event The desired HostMultiplayerEvent.
     */
    virtual void on_host(const HostMultiplayerEvent &event) {}
};

#endif //ENGINE_MULTIPLAYER_LISTENER_HPP
