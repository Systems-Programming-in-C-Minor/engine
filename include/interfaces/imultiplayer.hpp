
#ifndef ENGINE_IMULTIPLAYER_HPP
#define ENGINE_IMULTIPLAYER_HPP

#include <string>
#include <memory>
#include <list>
#include "inetworkable.hpp"

/**
 * @brief Interface for the multiplayer implementation.
 */
class IMultiplayer {
private:
    std::list<std::shared_ptr<INetworkable>> _networkables;

protected:
    /**
     * @brief Default constructor.
     */
    IMultiplayer() = default;

public:
    /**
     * @brief Register a networkable object.
     * @param networkable The INetworkable which will be registered.
     */
    void register_networkable(const std::shared_ptr<INetworkable> &networkable);

    /**
     * @brief Initialize the IMultiplayer object.
     *        Override for implementing the desired behaviour.
     */
    virtual void initialize() = 0;

    /**
     * @brief Method which gets called every tick.
     *        Override for implementing the desired behaviour.
     * */
    virtual void tick() = 0;

    /**
     * @brief Connect the IMultiplayer object.
     *        Override for implementing the desired behaviour.
     */
    virtual void connect() = 0;

    /**
     * @brief Disconnect the IMultiplayer object.
     *        Override for implementing the desired behaviour.
     */
    virtual void disconnect() = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IMultiplayer() = default;
};

#endif //ENGINE_IMULTIPLAYER_HPP
