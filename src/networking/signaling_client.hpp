#pragma once

#include <steam/steamnetworkingcustomsignaling.h>

/// Interface to our client.
class ISignalingClient {
public:

    /// Create signaling object for a connection to peer
    virtual ISteamNetworkingConnectionSignaling *CreateSignalingForConnection(
            const SteamNetworkingIdentity &identityPeer,
            SteamNetworkingErrMsg &errMsg) = 0;

    /// Poll the server for incoming signals and dispatch them.
    /// We use polling in this example just to keep it simple.
    /// You could use a service thread.
    virtual void Poll() = 0;

    /// Disconnect from the server and close down our polling thread.
    virtual void Release() = 0;
};

// Start connecting to the signaling server.
ISignalingClient *CreateSignalingClient(
        const char *address, // Address:port
        ISteamNetworkingSockets *pSteamNetworkingSockets, // Where should we send signals when we get them?
        SteamNetworkingErrMsg &errMsg // Error message is returned here if we fail
);
