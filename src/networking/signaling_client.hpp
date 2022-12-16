#pragma once

#include <steam/steamnetworkingcustomsignaling.h>

/// Interface to our client.
class ISignalingClient {
public:

    /// Create signaling object for a connection to peer
    virtual ISteamNetworkingConnectionSignaling *CreateSignalingForConnection(
            const SteamNetworkingIdentity &identity_peer,
            SteamNetworkingErrMsg &error_message) = 0;

    /// poll the server for incoming signals and dispatch them.
    /// We use polling in this example just to keep it simple.
    /// You could use a service thread.
    virtual void poll() = 0;

    /// Disconnect from the server and close down our polling thread.
    virtual void release() = 0;
};

// Start connecting to the signaling server.
ISignalingClient *CreateSignalingClient(
        const char *address, // Address:port
        ISteamNetworkingSockets *steam_networking_sockets, // Where should we send signals when we get them?
        SteamNetworkingErrMsg &error_message // Error message is returned here if we fail
);
