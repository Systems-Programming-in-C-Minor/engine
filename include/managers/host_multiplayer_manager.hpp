
#ifndef ENGINE_HOST_MULTIPLAYER_MANAGER_HPP
#define ENGINE_HOST_MULTIPLAYER_MANAGER_HPP

#include "interfaces/imultiplayer.hpp"

/**
 * @brief Manager which handles multiplayer for the host.
 */
class HostMultiplayerManager : public IMultiplayer {
public:
    /**
     * @brief Explicit constructor.
     * @param user_id User id for the host system.
     */
    explicit HostMultiplayerManager(std::string user_id);

    /**
     * @brief Initialize the HostMultiplayerManager.
     */
    void initialize() override;

    /**
     * @brief Method which gets called every tick.
     * */
    void tick() override;

    /**
     * @brief Connect the HostMultiplayerManager.
     */
    void connect() override;

    /**
     * @brief Disconnect the HostMultiplayerManager.
     */
    void disconnect() override;

};

#endif //ENGINE_HOST_MULTIPLAYER_MANAGER_HPP
