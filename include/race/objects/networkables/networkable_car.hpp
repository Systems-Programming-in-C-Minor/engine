#pragma once

#include <memory>
#include <iostream>
#include "interfaces/inetworkable.hpp"
#include "race/objects/car.hpp"

class NetworkableCar : public INetworkable {
private:
    std::shared_ptr<Car> _car;

public:
    NetworkableCar(const std::shared_ptr<Car>& car, bool transmit, bool receive) :
            _car(car), INetworkable(car->get_name(), transmit, receive) {}

    std::string serialize() override;

    void deserialize(const std::string &import_json) override;
};