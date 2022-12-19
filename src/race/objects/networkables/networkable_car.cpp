#include "race/objects/networkables/networkable_car.hpp"
#include "../../../json_converters.hpp"


std::string NetworkableCar::serialize() {
    auto data = nlohmann::json();
    data["transform"] = _car->transform;
    return data.dump();
}

void NetworkableCar::deserialize(const std::string &import_json) {
    auto data = nlohmann::json::parse(import_json);
    _car->transform = data.at("transform").get<Transform>();
}
