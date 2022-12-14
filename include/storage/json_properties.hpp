#ifndef ENGINE_JSONPROPERTIES_HPP
#define ENGINE_JSONPROPERTIES_HPP

#include <fstream>
#include "iproperties.hpp"


class JsonProperties : public IProperties {
private:
    mutable std::fstream current_filestream;
public:
    explicit JsonProperties(const std::string &filepath);

    void set_property(std::string name, std::string value) override;

    [[nodiscard]] std::optional<std::string> get_property(std::string name) const override;
};

#endif //ENGINE_JSONPROPERTIES_HPP
