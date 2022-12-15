#include "networking/networking_test.hpp"
#include "multiplayer_client.hpp"

void NetworkingTest::client() {
    auto x = MultiplayerClient("James", "Maik", "signaling.maik.sh:10000");
    x.connect();
}
