#include "time.hpp"
#include <chrono>

using namespace std::chrono;

float Time::delta_time() const {
    const auto dur = steady_clock::now() - _time_since_call;
    return duration<float>(dur).count() * 1000.f + 1.f;
}

double Time::time_scale() const {
    return _time_scale;
}

void Time::time_scale(double new_time_scale) {
    _time_scale = new_time_scale;
}

void Time::tick() {
    _time_since_call = steady_clock::now();
}
