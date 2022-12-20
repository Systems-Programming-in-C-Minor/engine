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
    std::list<std::function<void()>> _host_callbacks;
    std::list<std::function<void(int)>> _user_join_callbacks;
    std::list<std::function<void(int)>> _user_leave_callbacks;
    std::list<std::function<void(int)>> _user_allocation_callbacks;
    std::list<std::function<void(std::list<int>)>> _users_callbacks;

    void _tick();

public:
    explicit MultiplayerClient(const std::string &signaling_server);

    void initialize() override;

    void tick() override;

    void on_host(std::function<void()> callback) override;

    void on_user_join(std::function<void(int id)> callback) override;

    void on_user_leave(std::function<void(int id)> callback) override;

    void on_user_allocation(std::function<void(int id)> callback) override;

    void on_users(std::function<void(std::list<int> ids)> callback) override;

    ~MultiplayerClient() override;
};