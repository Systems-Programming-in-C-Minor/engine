#pragma once

#include <thread>

#include "interfaces/imultiplayer.hpp"
#include "asio/io_context.hpp"
#include "network_client.hpp"


class MultiplayerClient : public IMultiplayer {
private:
    asio::io_context _io_context;
    NetworkClient _network_client;
    std::thread _networking_thread;
    std::deque<std::string> _received_messages;
    std::mutex _received_messages_mutex;

    void _tick();

public:
    explicit MultiplayerClient(const std::string &signaling_server);

    void tick() override;

    ~MultiplayerClient() override;
};