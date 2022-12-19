#include "networking/networking_test.hpp"
#include "multiplayer_client.hpp"
#include "multiplayer_host.hpp"

class Test : public INetworkable {
public:
    Test() : INetworkable("Test") {};

    std::string serialize() const override {
        return "NMEEESBWHbfhjebwrhjfbjkw";
    };
    
    void deserialize(const std::string &import_json) override {

    };
};

void NetworkingTest::client() {
    auto client = MultiplayerClient("player_b", "localhost:10000");

    client.register_networkable(std::make_shared<Test>());

    client.tick();
}

void NetworkingTest::host() {
//    auto x = MultiplayerHost("player_a", "localhost:10000");
//    x.connect();
}