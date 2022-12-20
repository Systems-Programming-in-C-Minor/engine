#include "interfaces/imultiplayer.hpp"

void IMultiplayer::register_networkable(const std::shared_ptr<INetworkable> &networkable) {
    _networkables.emplace_back(networkable);
}
