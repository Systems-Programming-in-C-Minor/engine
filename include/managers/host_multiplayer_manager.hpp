
#ifndef ENGINE_HOST_MULTIPLAYER_MANAGER_HPP
#define ENGINE_HOST_MULTIPLAYER_MANAGER_HPP

#include "./multiplayer_manager.hpp"

class HostMultiplayerManager : public MultiplayerManager {
public:
    explicit HostMultiplayerManager(std::string  user_id);

    void initialize() override;

    void tick() override;

    void connect() override;

    void disconnect() override;

};

#endif //ENGINE_HOST_MULTIPLAYER_MANAGER_HPP
