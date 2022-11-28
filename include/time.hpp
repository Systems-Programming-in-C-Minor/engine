#ifndef ENGINE_TIME_HPP
#define ENGINE_TIME_HPP

#include <chrono>
using namespace std::chrono;

class Time {
public:
    Time();

    double delta_time();
    double time_scale();
    void time_scale(double new_time_scale);
    void tick();
    double _time_scale;

private:
    time_point<steady_clock> _time_since_call;

};

#endif //ENGINE_TIME_HPP
