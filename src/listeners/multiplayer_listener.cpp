#include "../include/listeners/multiplayer_listener.hpp"

MultiplayerListener::MultiplayerListener(EventManager &event_manager) {
    event_manager.register_listener(UserJoinedMultiplayer, [this](const IEvent &event) {
        on_user_join(dynamic_cast<const UserJoinedMultiplayerEvent &>(event));
    });
    event_manager.register_listener(UserLeftMultiplayer, [this](const IEvent &event) {
        on_user_leave(dynamic_cast<const UserLeftMultiplayerEvent &>(event));
    });
    event_manager.register_listener(AllocationMultiplayer, [this](const IEvent &event) {
        on_allocation(dynamic_cast<const AllocationMultiplayerEvent &>(event));
    });
    event_manager.register_listener(UsersMultiplayer, [this](const IEvent &event) {
        on_users(dynamic_cast<const UsersMultiplayerEvent &>(event));
    });
    event_manager.register_listener(HostMultiplayer, [this](const IEvent &event) {
        on_host(dynamic_cast<const HostMultiplayerEvent &>(event));
    });
    event_manager.register_listener(StartGameMultiplayer, [this](const IEvent &event) {
        on_start_game(dynamic_cast<const StartGameMultiplayerEvent &>(event));
    });
    event_manager.register_listener(StopGameMultiplayer, [this](const IEvent &event) {
        on_stop_game(dynamic_cast<const StopGameMultiplayerEvent &>(event));
    });
}
