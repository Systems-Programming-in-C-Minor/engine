#include <utility>

#include "interfaces/imultiplayer.hpp"

IMultiplayer::IMultiplayer(std::string user_id) : user_id(std::move(user_id)) {

}

void IMultiplayer::register_networkable(const std::shared_ptr<INetworkable> &networkable) {
    _networkables.emplace_back(networkable);
}
