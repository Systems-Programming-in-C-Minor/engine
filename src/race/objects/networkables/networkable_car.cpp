#include "race/objects/networkables/networkable_car.hpp"
#include "../../../json_converters.hpp"


std::string NetworkableCar::serialize() {
    auto data = nlohmann::json();
    data["transform"] = car->transform.serialize();
    return data.dump();
}

void NetworkableCar::deserialize(const std::string &import_json) {
    auto data = nlohmann::json::parse(import_json);
    car->transform.deserialize(data.at("transform").get<std::string>());
}
