
#ifndef ENGINE_IMULTIPLAYER_HPP
#define ENGINE_IMULTIPLAYER_HPP

#include <string>
#include <memory>
#include <list>
#include <functional>
#include "inetworkable.hpp"

/**
 * @brief Interface for the multiplayer implementation.
 */
class IMultiplayer {
protected:
    std::list<std::shared_ptr<INetworkable>> _networkables;

    /**
     * @brief Default constructor.
     */
    IMultiplayer() = default;

public:
    bool is_host = false; // Only available after first tick

    /**
     * @brief Register a networkable object.
     * @param networkable The INetworkable which will be registered.
     */
    void register_networkable(const std::shared_ptr<INetworkable> &networkable);

    /**
     * @brief Method which gets called every tick.
     *        Override for implementing the desired behaviour.
     * */
    virtual void tick() = 0;

    /**
     * @brief Sends a StartGame event to the server.
     * */
    virtual void start_game() = 0;

    /**
     * @brief Sends a StopGame event to the server.
     * */
    virtual void stop_game() = 0;


    virtual ~IMultiplayer() = default;
};

#endif //ENGINE_IMULTIPLAYER_HPP
