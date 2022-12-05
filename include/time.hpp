#ifndef ENGINE_TIME_HPP
#define ENGINE_TIME_HPP

#include <chrono>

class Time {
public:
    Time();

    [[nodiscard]] double delta_time() const;

    [[nodiscard]] double time_scale() const;

    void time_scale(double new_time_scale);

    void tick();

private:
    std::chrono::steady_clock::time_point _time_since_call;

    double _time_scale;
};

#endif //ENGINE_TIME_HPP