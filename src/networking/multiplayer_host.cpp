#include "multiplayer_host.hpp"

#include <utility>


MultiplayerHost::MultiplayerHost(const std::string& player_name, const std::string& signaling_server) :
        IMultiplayer(),
        SteamNetworking(player_name, signaling_server) {

}

void MultiplayerHost::initialize() {

}

void MultiplayerHost::tick() {

}

void MultiplayerHost::connect() {

}

void MultiplayerHost::disconnect() {

}
