#ifndef ENGINE_INETWORKABLE_HPP
#define ENGINE_INETWORKABLE_HPP

#include <string>
#include <utility>
#include "../components/component.hpp"

/**
 * @brief Interface for objects which are networkable.
 */
class INetworkable : public Component {
private:
    const std::string _id;

protected:
    /**
     * @brief Explicit constructor.
     * @param id The id of the INetworkable object.
     */
    explicit INetworkable(std::string id) : _id(std::move(id)) {}

public:
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

    /**
     * @brief Return the id of the INetworkable object.
     * @return The current id as an int.
     */
    [[nodiscard]] std::string get_id() const {
        return _id;
    }
};

#endif //ENGINE_INETWORKABLE_HPP
