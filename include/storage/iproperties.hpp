#ifndef ENGINE_IPROPERTIES_HPP
#define ENGINE_IPROPERTIES_HPP

#include <string>
#include <optional>

class iproperties {
    virtual void set_property(std::string name, std::string value) = 0;

    virtual std::optional<std::string> get_property(std::string name) = 0;
};

#endif //ENGINE_IPROPERTIES_HPP
