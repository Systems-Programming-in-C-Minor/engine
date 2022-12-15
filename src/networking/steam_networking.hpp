#pragma once

#include <string>
#include "steam/steamnetworkingtypes.h"

class SteamNetworking {
private:
    SteamNetworkingIdentity identity{};
    HSteamListenSocket listen_socket{};
    HSteamNetConnection network_connection{};

    void onConnectionStatusChanged(SteamNetConnectionStatusChangedCallback_t *pInfo);
protected:
    SteamNetworking(const std::string &player_name, const std::string &signaling_server);
};
