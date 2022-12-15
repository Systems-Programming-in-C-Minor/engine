#include "steam_networking.hpp"
#include "steam/isteamnetworkingutils.h"
#include "steam/steamnetworkingsockets.h"
#include "signaling_client.hpp"
#include "fmt/format.h"

#include <iostream>
#include <functional>
#include <cassert>
#include <utility>


using NetConnectionStatusChangedCallback = std::function<void(SteamNetConnectionStatusChangedCallback_t *)>;


namespace Workaround {
    auto get_callback() -> NetConnectionStatusChangedCallback & {
        static NetConnectionStatusChangedCallback callback;
        return callback;
    }

    auto set_callback(NetConnectionStatusChangedCallback func) -> void {
        auto &callback = get_callback();
        callback = std::move(func);
    }

    void workaround1_callback_adapter(SteamNetConnectionStatusChangedCallback_t *pInfo) {
        get_callback()(pInfo);
    }

    void wrapper_to_SetGlobalCallback_SteamNetConnectionStatusChanged(NetConnectionStatusChangedCallback func) {
        set_callback(std::move(func));
        SteamNetworkingUtils()->SetGlobalCallback_SteamNetConnectionStatusChanged(&workaround1_callback_adapter);
    }
}

SteamNetworking::SteamNetworking(const std::string &player_name, const std::string &signaling_server) {
    identity.Clear();
    identity.ParseString(fmt::format("str:{}", player_name).c_str());


    SteamNetworkingUtils()->SetDebugOutputFunction(k_ESteamNetworkingSocketsDebugOutputType_Debug,
                                                   [](ESteamNetworkingSocketsDebugOutputType eType,
                                                      const char *pszMsg) {
                                                       std::cout << pszMsg << std::endl;
                                                   });

    SteamNetworkingUtils()->SetGlobalConfigValueInt32(k_ESteamNetworkingConfig_LogLevel_P2PRendezvous,
                                                      k_ESteamNetworkingSocketsDebugOutputType_Debug);

    SteamDatagramErrMsg errMsg;
    if (!GameNetworkingSockets_Init(&identity, errMsg)) {
        std::cout << errMsg << std::endl;
        exit(1);
    }

    // Hardcode STUN-servers
    SteamNetworkingUtils()->SetGlobalConfigValueString(k_ESteamNetworkingConfig_P2P_STUN_ServerList,
                                                       "stun.l.google.com:19302");

    // Allow sharing of any kind of ICE address.
    // We don't have any method of relaying (TURN) in this example, so we are essentially
    // forced to disclose our public address if we want to pierce NAT.  But if we
    // had relay fallback, or if we only wanted to connect on the LAN, we could restrict
    // to only sharing private addresses.
    SteamNetworkingUtils()->SetGlobalConfigValueInt32(k_ESteamNetworkingConfig_P2P_Transport_ICE_Enable,
                                                      k_nSteamNetworkingConfig_P2P_Transport_ICE_Enable_All);


    ISignalingClient *pSignaling = CreateSignalingClient(signaling_server.c_str(),
                                                         SteamNetworkingSockets(), errMsg);
    if (pSignaling == nullptr) {
        std::cout << "Failed to initializing signaling client. " << errMsg << std::endl;
        exit(1);
    }

    Workaround::wrapper_to_SetGlobalCallback_SteamNetConnectionStatusChanged(
            [&](SteamNetConnectionStatusChangedCallback_t *pInfo) {
                onConnectionStatusChanged(pInfo);
            });
}

void
SteamNetworking::onConnectionStatusChanged(SteamNetConnectionStatusChangedCallback_t *pInfo) {
    fmt::print("Connection status changed!!!");

    // What's the state of the connection?
    switch (pInfo->m_info.m_eState) {
        case k_ESteamNetworkingConnectionState_ClosedByPeer:
        case k_ESteamNetworkingConnectionState_ProblemDetectedLocally:

            fmt::print("[{}] {}, reason {}: {}\n",
                       pInfo->m_info.m_szConnectionDescription,
                       (pInfo->m_info.m_eState == k_ESteamNetworkingConnectionState_ClosedByPeer ? "closed by peer"
                                                                                                 : "problem detected locally"),
                       pInfo->m_info.m_eEndReason,
                       pInfo->m_info.m_szEndDebug
            );

            // Close our end
            SteamNetworkingSockets()->CloseConnection(pInfo->m_hConn, 0, nullptr, false);

            if (network_connection == pInfo->m_hConn) {
                network_connection = k_HSteamNetConnection_Invalid;

                // In this example, we will bail the test whenever this happens.
                // Was this a normal termination?
                assert(!(k_ESteamNetworkingConnectionState_ProblemDetectedLocally == 0 ||
                         pInfo->m_info.m_eEndReason != k_ESteamNetConnectionEnd_App_Generic));

            } else {
                // Why are we hearing about any another connection?
                assert(false);
            }

            break;

        case k_ESteamNetworkingConnectionState_None:
            // Notification that a connection was destroyed.  (By us, presumably.)
            // We don't need this, so ignore it.
            break;

        case k_ESteamNetworkingConnectionState_Connecting:

            // Is this a connection we initiated, or one that we are receiving?
            if (listen_socket != k_HSteamListenSocket_Invalid && pInfo->m_info.m_hListenSocket == listen_socket) {
                // Somebody's knocking
                // Note that we assume we will only ever receive a single connection
                assert(network_connection ==
                       k_HSteamNetConnection_Invalid); // not really a bug in this code, but a bug in the test

                printf("[%s] Accepting\n", pInfo->m_info.m_szConnectionDescription);
                network_connection = pInfo->m_hConn;
                SteamNetworkingSockets()->AcceptConnection(pInfo->m_hConn);
            } else {
                // Note that we will get notification when our own connection that
                // we initiate enters this state.
                assert(network_connection == pInfo->m_hConn);
                printf("[%s] Entered connecting state\n", pInfo->m_info.m_szConnectionDescription);
            }
            break;

        case k_ESteamNetworkingConnectionState_FindingRoute:
            // P2P connections will spend a brief time here where they swap addresses
            // and try to find a route.
            printf("[%s] finding route\n", pInfo->m_info.m_szConnectionDescription);
            break;

        case k_ESteamNetworkingConnectionState_Connected:
            // We got fully connected
            assert(pInfo->m_hConn ==
                   network_connection); // We don't initiate or accept any other connections, so this should be out own connection
            printf("[%s] connected\n", pInfo->m_info.m_szConnectionDescription);
            break;

        default:
            assert(false);
    }
}

