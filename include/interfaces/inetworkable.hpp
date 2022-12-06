#ifndef ENGINE_INETWORKABLE_HPP
#define ENGINE_INETWORKABLE_HPP

#include "string"
#include "../components/component.hpp"

class INetworkable : public Component {
private:
    const std::string _id;

public:

    INetworkable(const std::string id) : _id(id) {}

    virtual std::string serialize() = 0;

    virtual void deserialize(std::string import) = 0;

    std::string get_id() const {
        return _id;
    }
};

#endif //ENGINE_INETWORKABLE_HPP
