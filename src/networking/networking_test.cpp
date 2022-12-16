#include "networking/networking_test.hpp"
#include "multiplayer_client.hpp"
#include "multiplayer_host.hpp"

void NetworkingTest::client() {
    auto x = MultiplayerClient("James", "Maik", "signaling.maik.sh:10000");
    x.connect();
}

void NetworkingTest::host() {
    auto x = MultiplayerHost("Maik", "signaling.maik.sh:10000");
    x.connect();
}