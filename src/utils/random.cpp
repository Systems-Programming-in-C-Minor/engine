#include <random>
#include "utils/random.hpp"

int Random::random(int max, int min) {
    std::random_device device;
    std::default_random_engine engine{device()};

    std::uniform_int_distribution<int> dist{min, max};
    return dist(engine);
}

int Random::random(float max, float min) {
    return random(static_cast<int>( max), static_cast<int>(min));
}

float Random::random_f(float min, float max) {
    std::random_device device;
    std::default_random_engine engine{device()};

    std::uniform_int_distribution<long> dist{(long) min, (long)max};
    return (float) dist(engine);
}

bool Random::random_bool() {
    return random() == 1;
}
