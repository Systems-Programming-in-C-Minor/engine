
#ifndef ENGINE_IMULTIPLAYER_HPP
#define ENGINE_IMULTIPLAYER_HPP

#include <string>
#include <memory>
#include <vector>
#include "inetworkable.hpp"

class IMultiplayer {
private:
    std::vector<std::shared_ptr<INetworkable>> _networkables;

protected:
    explicit IMultiplayer(std::string  user_id);

public:
    const std::string user_id;

    void register_networkable(const std::shared_ptr<INetworkable>& networkable);

    virtual void initialize() = 0;

    virtual void tick() = 0;

    virtual void connect() = 0;

    virtual void disconnect() = 0;

    virtual ~IMultiplayer() = default;
};

#endif //ENGINE_IMULTIPLAYER_HPP
