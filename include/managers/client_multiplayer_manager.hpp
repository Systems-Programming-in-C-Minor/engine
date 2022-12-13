
#ifndef ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP
#define ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP

#include "interfaces/imultiplayer.hpp"

class ClientMultiplayerManager : public IMultiplayer {
public:
    explicit ClientMultiplayerManager(std::string  user_id);

    void initialize() override;

    void tick() override;

    void connect() override;

    void disconnect() override;

};

#endif //ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP
