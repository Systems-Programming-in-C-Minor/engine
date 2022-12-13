#ifndef ENGINE_TIME_HPP
#define ENGINE_TIME_HPP

#include <chrono>

class Time {
public:
    /**
     * Get the time from the previous tick to time of call in milliseconds
     * @return
     */
    [[nodiscard]] float delta_time() const;

    [[nodiscard]] double time_scale() const;

    void time_scale(double new_time_scale);

    void tick();

private:
    std::chrono::steady_clock::time_point _time_since_call;

    double _time_scale = 1;
};

#endif //ENGINE_TIME_HPP
