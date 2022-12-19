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

public:
    MultiplayerClient(const std::string& player_name, const std::string& signaling_server);

    void initialize() override;

    void tick() override;

    ~MultiplayerClient() override;
};