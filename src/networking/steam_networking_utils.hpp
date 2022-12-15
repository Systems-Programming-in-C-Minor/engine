#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <thread>
#include <cassert>
#include <vector>
#include "signaling_client.hpp"

#include <box2d/box2d.h>
#include <SDL2/SDL.h>
#include <steam/steamnetworkingsockets.h>
#include <steam/isteamnetworkingutils.h>

class SteamNetConnectionStatusChangedCallback_t;

enum ETestRole {
    k_ETestRole_Undefined,
    k_ETestRole_Server,
    k_ETestRole_Client,
    k_ETestRole_Symmetric,
};

void Quit(int rc);

// Send a simple string message to out peer, using reliable transport.
void SendMessageToPeer(const char *pszMsg);

// Called when a connection undergoes a state transition.
void OnSteamNetConnectionStatusChanged(SteamNetConnectionStatusChangedCallback_t *pInfo);

int run(int argc, const char **argv);
