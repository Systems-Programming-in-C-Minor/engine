#ifndef ENGINE_IPROPERTIES_HPP
#define ENGINE_IPROPERTIES_HPP

#include <string>
#include <optional>

class IProperties {
public:
    virtual void set_property(std::string name, std::string value) = 0;

    [[nodiscard]] virtual std::optional<std::string> get_property(std::string name) const = 0;

    virtual ~IProperties() = default;
};

#endif //ENGINE_IPROPERTIES_HPP
