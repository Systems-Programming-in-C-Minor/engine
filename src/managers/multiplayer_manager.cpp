#include <utility>

#include "../include/managers/multiplayer_manager.hpp"

MultiplayerManager::MultiplayerManager(std::string user_id) : user_id(std::move(user_id)) {

}

void MultiplayerManager::register_networkable(const std::shared_ptr<INetworkable> &networkable) {

}
