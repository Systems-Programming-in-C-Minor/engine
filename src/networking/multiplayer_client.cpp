#include "multiplayer_client.hpp"
#include "network_client.hpp"


MultiplayerClient::MultiplayerClient(const std::string &player_name, const std::string &signaling_server) :
        _io_context(asio::io_context()),
        _network_client(_io_context, signaling_server) {
    _networking_thread = std::thread([&]() { _io_context.run(); });

    // Wait a little for the connection to be opened
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void MultiplayerClient::initialize() {

}

void MultiplayerClient::tick() {
    for (const auto &networkable: _networkables) {
        const auto serialized_data = networkable->serialize();
        const auto message = NetworkMessage(serialized_data);
        _network_client.write(message);
    }
}

MultiplayerClient::~MultiplayerClient() {
    _network_client.close();
    _networking_thread.join();
}
