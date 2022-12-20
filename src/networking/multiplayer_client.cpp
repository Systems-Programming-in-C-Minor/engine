#include "multiplayer_client.hpp"
#include "network_client.hpp"
#include "nlohmann/json.hpp"
#include "global.hpp"
#include "events.hpp"

using json = nlohmann::json;


MultiplayerClient::MultiplayerClient(const std::string &signaling_server) :
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

void MultiplayerClient::_tick() {
    const std::lock_guard<std::mutex> lock(_received_messages_mutex);

    const auto global = Global::get_instance();

    while (!_received_messages.empty()) {
        const auto &message = _received_messages.front();
        const auto data = json::parse(message);

        switch (data.at("type").get<NetworkableType>()) {
            case Host:
                is_host = true;
                global->notify_event_manager(HostMultiplayerEvent());
                break;
            case Join:
                global->notify_event_manager(UserJoinedMultiplayerEvent(data["user_id"]));
                break;
            case Leave:
                global->notify_event_manager(UserLeftMultiplayerEvent(data["user_id"]));
                break;
            case Allocation:
                global->notify_event_manager(AllocationMultiplayerEvent(data["user_id"]));
                break;
            case Users:
                global->notify_event_manager(UsersMultiplayerEvent(data.at("user_ids").get<std::list<int>>()));
                break;
            case Update: {
                for (const auto &networkable: _networkables) {
                    if (!networkable->receive) continue;

                    if (data["id"] != networkable->id) continue;

                    networkable->deserialize(data["data"]);
                }
                break;
            }
        }

        _received_messages.pop_front();
    }

    for (const auto &networkable: _networkables) {
        if (!networkable->transmit) continue;

        auto data = json();
        data["id"] = networkable->id;
        data["type"] = networkable->type;
        data["data"] = networkable->serialize();

        const auto message = NetworkMessage(data.dump());
        _network_client.write(message);
    }
}

void MultiplayerClient::tick() {
    _tick();
}

MultiplayerClient::~MultiplayerClient() {
    // Wait a little for queued messages to be sent
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    _network_client.close();
    _networking_thread.join();
}
