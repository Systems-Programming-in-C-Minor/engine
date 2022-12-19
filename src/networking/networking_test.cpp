#include "networking/networking_test.hpp"
#include "multiplayer_client.hpp"
#include "multiplayer_host.hpp"

class Test1 : public INetworkable {
public:
    Test1() : INetworkable("Test1", true, true) {};


    [[nodiscard]] std::string serialize() const override {
        return "Test1 message";
    };

    void deserialize(const std::string &import_json) override {
        std::cout << "deserializing1: " << import_json << std::endl;
    };
};

class Test2 : public INetworkable {
public:
    Test2() : INetworkable("Test2", true, false) {};

    [[nodiscard]] std::string serialize() const override {
        return "Test2 message";
    };

    void deserialize(const std::string &import_json) override {
        std::cout << "deserializing2: " << import_json << std::endl;
    };
};

void NetworkingTest::client() {
    auto client = MultiplayerClient("player_b", "localhost:10000");

    client.register_networkable(std::make_shared<Test1>());
    client.register_networkable(std::make_shared<Test2>());

    client.tick();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    client.tick();
}

void NetworkingTest::host() {
//    auto x = MultiplayerHost("player_a", "localhost:10000");
//    x.connect();
}
