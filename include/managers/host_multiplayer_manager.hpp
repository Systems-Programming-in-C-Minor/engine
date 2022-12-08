
#ifndef ENGINE_HOST_MULTIPLAYER_MANAGER_HPP
#define ENGINE_HOST_MULTIPLAYER_MANAGER_HPP

#include "interfaces/imultiplayer.hpp"

class HostMultiplayerManager : public IMultiplayer {
public:
    explicit HostMultiplayerManager(std::string  user_id);

    void initialize() override;

    void tick() override;

    void connect() override;

    void disconnect() override;

};

#endif //ENGINE_HOST_MULTIPLAYER_MANAGER_HPP
