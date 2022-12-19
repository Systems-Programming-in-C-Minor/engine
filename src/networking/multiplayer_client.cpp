#include "multiplayer_client.hpp"
#include "network_client.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;


MultiplayerClient::MultiplayerClient(const std::string &player_name, const std::string &signaling_server) :
        _io_context(asio::io_context()),
        _network_client(_io_context, signaling_server) {
    _networking_thread = std::thread([&]() { _io_context.run(); });

    _network_client.on_message([&](const std::string &message) {
        const std::lock_guard<std::mutex> lock(_received_messages_mutex);
        _received_messages.push_back(message);
    });

    // Wait a little for the connection to be opened
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
}

void MultiplayerClient::initialize() {

}

void MultiplayerClient::tick() {
    const std::lock_guard<std::mutex> lock(_received_messages_mutex);

    while (!_received_messages.empty()) {
        const auto &message = _received_messages.front();
        const auto data = json::parse(message);

        for (const auto &networkable: _networkables) {
            if (!networkable->receive) continue;

            if (data["id"] != networkable->get_id()) continue;

            networkable->deserialize(data["data"]);
        }

        _received_messages.pop_front();
    }

    for (const auto &networkable: _networkables) {
        if (!networkable->transmit) continue;

        auto data = json();
        data["id"] = networkable->get_id();
        data["data"] = networkable->serialize();

        const auto message = NetworkMessage(data.dump());
        _network_client.write(message);
    }
}

MultiplayerClient::~MultiplayerClient() {
    // Wait a little for queued messages to be sent
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    _network_client.close();
    _networking_thread.join();
}
