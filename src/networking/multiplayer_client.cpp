#include "multiplayer_client.hpp"
#include "fmt/format.h"


MultiplayerClient::MultiplayerClient(const std::string &player_name, const std::string &host_player_name,
                                     const std::string &signaling_server) :
        IMultiplayer(),
        SteamNetworking(player_name, signaling_server) {
    remoteIdentity.Clear();
    remoteIdentity.ParseString(fmt::format("str:{}", host_player_name).c_str());
}

void MultiplayerClient::initialize() {

}

void MultiplayerClient::tick() {

}

void MultiplayerClient::connect() {

}

void MultiplayerClient::disconnect() {

}
