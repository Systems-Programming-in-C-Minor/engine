#include <nlohmann/json.hpp>
#include "storage/json_properties.hpp"

using json = nlohmann::json;
using ios = std::ios;

JsonProperties::JsonProperties(const std::string &filepath) {
    if (!std::filesystem::exists(filepath)) {
        std::ofstream(filepath) << "{}" << std::endl;
    }

    current_filestream = std::fstream(filepath, ios::in | ios::out);
}

void JsonProperties::set_property(std::string name, std::string value) {
    current_filestream.seekg(ios::beg);
    json data = json::parse(current_filestream);
    data[name] = value;
    current_filestream.seekg(ios::beg);
    current_filestream << data.dump() << std::endl;
}

std::optional<std::string> JsonProperties::get_property(std::string name) const {
    current_filestream.seekg(ios::beg);
    json data = json::parse(current_filestream);

    if (!data.contains(name)) {
        return std::nullopt;
    }

    return data[name];
}
