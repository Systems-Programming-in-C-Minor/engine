#ifndef ENGINE_MULTIPLAYER_LISTENER_HPP
#define ENGINE_MULTIPLAYER_LISTENER_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

/**
 * @brief Used for listening for multiplayer events.
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
     * @brief Called when a user joins the session.
     * @param event The desired UserJoinedMultiplayerEvent.
     */
    virtual void on_user_join(const UserJoinedMultiplayerEvent &event) {}

    /**
     * @brief Called when a user leaves the session.
     * @param event The desired UserLeftMultiplayerEvent.
     */
    virtual void on_user_leave(const UserLeftMultiplayerEvent &event) {}

    /**
     * @brief Called when an id is allocated to the user.
     * @param event The desired AllocationMultiplayerEvent.
     */
    virtual void on_allocation(const AllocationMultiplayerEvent &event) {}

    /**
     * @brief Called when the user count changes.
     * @param event The desired UsersMultiplayerEvent.
     */
    virtual void on_users(const UsersMultiplayerEvent &event) {}

    /**
     * @brief Called when the user is assigned to be the host, can be called at any point.
     * @param event The desired HostMultiplayerEvent.
     */
    virtual void on_host(const HostMultiplayerEvent &event) {}

    /**
     * @brief Called when the game starts.
     * @param event The desired StartGameMultiplayerEvent.
     */
    virtual void on_start_game(const StartGameMultiplayerEvent &event) {}

    /**
     * @brief Called when the game stops.
     * @param event The desired StopGameMultiplayerEvent.
     */
    virtual void on_stop_game(const StopGameMultiplayerEvent &event) {}
};

#endif //ENGINE_MULTIPLAYER_LISTENER_HPP
