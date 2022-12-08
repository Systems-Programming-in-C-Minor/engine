
#ifndef ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP
#define ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP

#include "./multiplayer_manager.hpp"

class ClientMultiplayerManager : public MultiplayerManager {
public:
    explicit ClientMultiplayerManager(std::string  user_id);

    void initialize() override;

    void tick() override;

    void connect() override;

    void disconnect() override;

};

#endif //ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP
