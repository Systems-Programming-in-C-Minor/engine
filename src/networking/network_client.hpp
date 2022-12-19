#ifndef ENGINE_NETWORK_CLIENT_HPP
#define ENGINE_NETWORK_CLIENT_HPP

#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <asio.hpp>
#include "chat_message.hpp"

class NetworkClient {
private:
    asio::io_context &_io_context;
    asio::ip::tcp::socket _socket;
    NetworkMessage _read_msg;
    std::deque<NetworkMessage> _write_msgs;

    void _connect(const asio::ip::tcp::resolver::results_type &endpoints);

    void _read_header();

    void _read_body();

    void _write();

public:
    NetworkClient(asio::io_context &io_context, const std::string &signaling_server);

    void write(const NetworkMessage &msg);

    void close();
};

#endif // ENGINE_NETWORK_CLIENT_HPP
