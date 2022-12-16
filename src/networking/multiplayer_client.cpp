#include "multiplayer_client.hpp"

#include <vector>
#include <cassert>

#include "fmt/format.h"
#include "steam/isteamnetworkingutils.h"
#include "steam/steamnetworkingsockets.h"


MultiplayerClient::MultiplayerClient(const std::string &player_name, const std::string &host_player_name,
                                     const std::string &signaling_server) :
        IMultiplayer(),
        SteamNetworking(player_name, signaling_server) {
    remote_identity.Clear();
    remote_identity.ParseString(fmt::format("str:{}", host_player_name).c_str());

    std::vector<SteamNetworkingConfigValue_t> vecOpts;

    // If we want the local and virtual port to differ, we must set
    // an option.  This is a pretty rare use case, and usually not needed.
    // The local virtual port is only usually relevant for symmetric
    // connections, and then, it almost always matches.  Here we are
    // just showing in this example code how you could handle this if you
    // needed them to differ.
    if (virtual_remote_port != virtual_local_port) {
        auto opt = SteamNetworkingConfigValue_t();
        opt.SetInt32(k_ESteamNetworkingConfig_LocalVirtualPort, virtual_local_port);
        vecOpts.push_back(opt);
    }


    printf("Connecting to '%s', virtual port %d, from local virtual port %d.\n",
           SteamNetworkingIdentityRender(remote_identity).c_str(), virtual_remote_port,
           virtual_local_port);

    // Connect using the "custom signaling" path.  Note that when
    // you are using this path, the identity is actually optional,
    // since we don't need it.  (Your signaling object already
    // knows how to talk to the peer) and then the peer identity
    // will be confirmed via rendezvous.
    SteamDatagramErrMsg errMsg;

    ISteamNetworkingConnectionSignaling *pConnSignaling = signaling_client->CreateSignalingForConnection(
            remote_identity,
            errMsg
    );
    assert(pConnSignaling);
    network_connection = SteamNetworkingSockets()->ConnectP2PCustomSignaling(pConnSignaling, &remote_identity,
                                                                             virtual_remote_port, (int) vecOpts.size(),
                                                                             vecOpts.data());
    assert(network_connection != k_HSteamNetConnection_Invalid);

    // Go ahead and send a message now.  The message will be queued until route finding
    // completes.
    send_message("Greetings!");


    for (;;) {
        // Check for incoming signals, and dispatch them
        signaling_client->poll();

        // Check callbacks
//        TEST_PumpCallbacks();

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

                // If we're the client, go ahead and shut down.  In this example we just
                // wanted to establish a connection and exchange a message, and we've done that.
                // Note that we use "linger" functionality.  This flushes out any remaining
                // messages that we have queued.  Essentially to us, the connection is closed,
                // but on thew wire, we will not actually close it until all reliable messages
                // have been confirmed as received by the client.  (Or the connection is closed
                // by the peer or drops.)  If we are the "client" role, then we know that no such
                // messages are in the pipeline in this test.  But in symmetric mode, it is
                // possible that we need to flush out our message that we sent.
                printf("Closing connection and shutting down.\n");
                SteamNetworkingSockets()->CloseConnection(network_connection, 0, "Test completed OK", true);
                break;
            }
        }
    }
}

void MultiplayerClient::initialize() {

}

void MultiplayerClient::tick() {

}

void MultiplayerClient::connect() {

}

void MultiplayerClient::disconnect() {

}
