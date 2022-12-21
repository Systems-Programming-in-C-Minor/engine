#ifndef ENGINE_INETWORKABLE_HPP
#define ENGINE_INETWORKABLE_HPP

#include <string>
#include <utility>
#include "../components/component.hpp"

/**
 * @brief Type of Networkable, contains events from the server.
 */
enum NetworkableType { // DO NOT CHANGE ORDER, the server has to have the same order to work
    Host,
    Join,
    Leave,
    Allocation,
    Users,
    Update,
    StartGame,
    StopGame,
};

/**
 * @brief Interface for objects which are networkable.
 */
class INetworkable : public Component {
protected:
    /**
     * @brief Constructor.
     * @param id The id of the INetworkable object.
     * @param type The type of networkable.
     * @param transmit Whether the object should be sent to other users.
     * @param receive Whether the object should be updated from other users.
     */
    INetworkable(std::string id, NetworkableType type, bool transmit, bool receive) : id(std::move(id)),
                                                                                      type(type),
                                                                                      transmit(transmit),
                                                                                      receive(receive) {}

public:
    const std::string id;
    const NetworkableType type;
    bool transmit;
    bool receive;

    /**
     * @brief Serialize the INetworkable object.
     * @return The serialized object as a std::string.
     */
    [[nodiscard]] virtual std::string serialize() const = 0;

    /**
     * @brief Deserialize the INetworkable object.
     * @param import_json The serialized std::string of the INetworkable object.
     */
    virtual void deserialize(const std::string &import_json) = 0;
};

#endif //ENGINE_INETWORKABLE_HPP
