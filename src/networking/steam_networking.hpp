#pragma once

#include <string>
#include "steam/steamnetworkingtypes.h"
#include "signaling_client.hpp"

class SteamNetworking {
private:
    void onConnectionStatusChanged(SteamNetConnectionStatusChangedCallback_t *pInfo);

protected:
    SteamNetworkingIdentity identity{};
    HSteamListenSocket listen_socket{};
    HSteamNetConnection network_connection{};

    ISignalingClient *signaling_client;

    int virtual_local_port{};
    int virtual_remote_port{};

    SteamNetworking(const std::string &player_name, const std::string &signaling_server);

public:
    void send_message(const std::string& message) const;
};
