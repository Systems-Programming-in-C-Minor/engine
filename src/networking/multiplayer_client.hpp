#pragma once

#include "interfaces/imultiplayer.hpp"
#include "steam_networking.hpp"

class MultiplayerClient : public IMultiplayer, protected SteamNetworking {
protected:
    SteamNetworkingIdentity remoteIdentity{};
public:
    MultiplayerClient(const std::string& player_name, const std::string& host_player_name, const std::string& signaling_server);

    void initialize() override;

    void tick() override;

    void connect() override;

    void disconnect() override;
};