#ifndef ENGINE_INETWORKABLE_HPP
#define ENGINE_INETWORKABLE_HPP

#include <string>
#include <utility>
#include "../components/component.hpp"

class INetworkable : public Component {
private:
    const std::string _id;

public:

    explicit INetworkable(std::string id) : _id(std::move(id)) {}

    virtual std::string serialize() = 0;

    virtual void deserialize(const std::string &import) = 0;

    [[nodiscard]] std::string get_id() const {
        return _id;
    }
};

#endif //ENGINE_INETWORKABLE_HPP
