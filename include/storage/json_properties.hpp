#ifndef ENGINE_JSONPROPERTIES_HPP
#define ENGINE_JSONPROPERTIES_HPP

#include <fstream>
#include "iproperties.hpp"


/**
 * @brief Class for json properties.
 */
class JsonProperties : public IProperties {
private:
    mutable std::fstream current_filestream;
public:
    /**
     * @brief Explicit constructor.
     * @param filepath The path where the properties will be stored.
     */
    explicit JsonProperties(const std::string &filepath);

    /**
     * @brief Setter for the properties.
     * @param name The name of the properties, which the value will be mapped to.
     * @param value The value of the properties.
     */
    void set_property(std::string name, std::string value) override;

    /**
     * @brief Getter for the properties.
     * @param name Return the properties mapped to this name.
     * @return If found, a std::string object.
     */
    [[nodiscard]] std::optional<std::string> get_property(std::string name) const override;
};

#endif //ENGINE_JSONPROPERTIES_HPP
