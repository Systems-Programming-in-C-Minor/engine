#ifndef ENGINE_IPROPERTIES_HPP
#define ENGINE_IPROPERTIES_HPP

#include <string>
#include <optional>

/**
 * @brief Interface for properties.
 */
class IProperties {
public:
    /**
     * @brief Setter for the properties.
     *        Override for implementing the desired behaviour.
     * @param name The name of the properties, which the value will be mapped to.
     * @param value The value of the properties.
     */
    virtual void set_property(std::string name, std::string value) = 0;

    /**
     * @brief Getter for the properties.
     *        Override for implementing the desired behaviour.
     * @param name Return the properties mapped to this name.
     * @return If found, a std::string object.
     */
    [[nodiscard]] virtual std::optional<std::string> get_property(std::string name) const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IProperties() = default;
};

#endif //ENGINE_IPROPERTIES_HPP
