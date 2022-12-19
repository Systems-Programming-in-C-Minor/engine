#pragma once

#include "interfaces/imultiplayer.hpp"
#include "network_client.hpp"

class MultiplayerHost : public IMultiplayer {
public:
    MultiplayerHost(const std::string& player_name, const std::string& signaling_server);

    void initialize() override;

    void tick() override;
};