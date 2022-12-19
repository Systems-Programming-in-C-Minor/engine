#include "network_client.hpp"

using asio::ip::tcp;

void NetworkClient::_connect(const asio::ip::basic_resolver<tcp, asio::any_io_executor>::results_type &endpoints) {
    asio::async_connect(_socket, endpoints,
                        [this](std::error_code ec, const tcp::endpoint &) {
                            if (!ec) {
                                _read_header();
                            }
                        });
}

void NetworkClient::_read_header() {
    asio::async_read(_socket,
                     asio::buffer(_read_msg.data(), NetworkMessage::header_length),
                     [this](std::error_code ec, std::size_t /*length*/) {
                         if (!ec && _read_msg.decode_header()) {
                             _read_body();
                         } else {
                             _socket.close();
                         }
                     });
}

void NetworkClient::_read_body() {
    asio::async_read(_socket,
                     asio::buffer(_read_msg.body(), _read_msg.body_length()),
                     [this](std::error_code ec, std::size_t /*length*/) {
                         if (!ec) {
                             const auto text = std::string(_read_msg.body(), _read_msg.body_length());
                             for (const auto &callback: _callbacks) {
                                 callback(text);
                             }
                             _read_header();
                         } else {
                             _socket.close();
                         }
                     });
}

void NetworkClient::_write() {
    asio::async_write(_socket,
                      asio::buffer(_write_msgs.front().data(),
                                   _write_msgs.front().length()),
                      [this](std::error_code ec, std::size_t /*length*/) {
                          if (!ec) {
                              _write_msgs.pop_front();
                              if (!_write_msgs.empty()) {
                                  _write();
                              }
                          } else {
                              _socket.close();
                          }
                      });
}

NetworkClient::NetworkClient(asio::io_context &io_context, const std::string &signaling_server) :
        _io_context(io_context), _socket(io_context) {

    const auto loc = signaling_server.find(':');
    const auto ip = signaling_server.substr(0, loc);
    const auto port = signaling_server.substr(loc+1);

    auto resolver = tcp::resolver(_io_context);
    const auto endpoints = resolver.resolve(ip, port);

    _connect(endpoints);
}

void NetworkClient::write(const NetworkMessage &msg) {
    asio::post(_io_context,
               [this, msg]() {
                   bool write_in_progress = !_write_msgs.empty();
                   _write_msgs.push_back(msg);
                   if (!write_in_progress) {
                       _write();
                   }
               });
}

void NetworkClient::close() {
    asio::post(_io_context, [this]() { _socket.close(); });
}

void NetworkClient::on_message(const std::function<void(std::string)>& callback) {
    _callbacks.push_back(callback);
}
