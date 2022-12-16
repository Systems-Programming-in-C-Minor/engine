#include <random>
#include "utils/random.hpp"

int Random::random(int max, int min) {
    std::random_device device;
    std::default_random_engine engine{device()};

    std::uniform_int_distribution<int> dist{min, static_cast<int>(max)};
    return dist(engine);
}

bool Random::random_bool() {
    return random() == 1;
}
