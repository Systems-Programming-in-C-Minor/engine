#include "multiplayer_host.hpp"
#include "steam/steamnetworkingsockets.h"

#include <cassert>


MultiplayerHost::MultiplayerHost(const std::string& player_name, const std::string& signaling_server) :
        IMultiplayer(),
        SteamNetworking(player_name, signaling_server) {
    printf("Creating listen socket, local virtual port %d\n", virtual_local_port);
    listen_socket = SteamNetworkingSockets()->CreateListenSocketP2P(virtual_local_port, 0, nullptr);
    assert(listen_socket != k_HSteamListenSocket_Invalid);



    for (;;) {
        // Check for incoming signals, and dispatch them
        signaling_client->poll();

        // If we have a connection, then poll it for messages
        if (network_connection != k_HSteamNetConnection_Invalid) {
            SteamNetworkingMessage_t *pMessage;
            int r = SteamNetworkingSockets()->ReceiveMessagesOnConnection(network_connection, &pMessage, 1);
            assert(r == 0 || r == 1); // <0 indicates an error
            if (r == 1) {
                // In this example code we will assume all messages are '\0'-terminated strings.
                // Obviously, this is not secure.
                printf("Received message '%s'\n", pMessage->GetData());

                // Free message struct and buffer.
                pMessage->Release();

                // We're the server.  Send a reply.
                send_message("I got your message");
            }
        }
    }
}

void MultiplayerHost::initialize() {

}

void MultiplayerHost::tick() {

}

void MultiplayerHost::connect() {

}

void MultiplayerHost::disconnect() {

}
