
#ifndef ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP
#define ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP

#include "interfaces/imultiplayer.hpp"

/**
 * @brief Manager which handles multiplayer for the client.
 */
class ClientMultiplayerManager : public IMultiplayer {
public:
    /**
     * @brief Explicit constructor.
     * @param user_id User id for the client system.
     */
    explicit ClientMultiplayerManager(std::string user_id);

    /**
     * @brief Initialize the ClientMultiplayerManager.
     */
    void initialize() override;

    /**
     * @brief Method which gets called every tick.
     * */
    void tick() override;

    /**
     * @brief Connect the ClientMultiplayerManager.
     */
    void connect() override;

    /**
     * @brief Disconnect the ClientMultiplayerManager.
     */
    void disconnect() override;

};

#endif //ENGINE_CLIENT_MULTIPLAYER_MANAGER_HPP
