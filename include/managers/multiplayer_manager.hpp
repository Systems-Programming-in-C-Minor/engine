
#ifndef ENGINE_MULTIPLAYER_MANAGER_HPP
#define ENGINE_MULTIPLAYER_MANAGER_HPP

#include <string>
#include <memory>
#include <vector>
#include "../interfaces/inetworkable.hpp"

class MultiplayerManager {
private:
    std::vector<std::shared_ptr<INetworkable>> _networkables;

protected:
    explicit MultiplayerManager(std::string  user_id);

public:
    const std::string user_id;


    void register_networkable(const std::shared_ptr<INetworkable>& networkable);

    virtual void initialize() = 0;

    virtual void tick() = 0;

    virtual void connect() = 0;

    virtual void disconnect() = 0;
};

#endif //ENGINE_MULTIPLAYER_MANAGER_HPP
