#pragma once

#include "interfaces/imultiplayer.hpp"
#include "steam_networking.hpp"

class MultiplayerHost : public IMultiplayer, protected SteamNetworking {
public:
    MultiplayerHost(const std::string& player_name, const std::string& signaling_server);

    void initialize() override;

    void tick() override;

    void connect() override;

    void disconnect() override;
};