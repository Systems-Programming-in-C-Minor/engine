#pragma once

#include <memory>
#include <iostream>
#include "interfaces/inetworkable.hpp"
#include "race/objects/car.hpp"

class NetworkableCar : public INetworkable {
public:
    Car* car;

    NetworkableCar(Car* car, bool transmit, bool receive) :
            car(car), INetworkable(car->get_name(), Update, transmit, receive) {}

    /**
     * @brief Serializes itself to json and returns it as a string.
     */
    [[nodiscard]] std::string serialize() const override;

    /**
     * @brief Unpacks the given json data and updates itself with the new values.
     * @param data Json string containing new data.
     */
    void deserialize(const std::string &import_json) override;
};