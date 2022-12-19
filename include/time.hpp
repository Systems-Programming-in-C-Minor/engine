#ifndef ENGINE_TIME_HPP
#define ENGINE_TIME_HPP

#include <chrono>

/**
 * @brief Class representing game time.
 */
class Time {
public:
    /**
     * brief Get the time from the previous tick to time of call in milliseconds
     * @return delta time value
     */
    [[nodiscard]] float delta_time() const;

    /**
     * @brief The scale at which time passes.
     * @return time scale value
     */
    [[nodiscard]] double time_scale() const;

    /**
     * @brief The setter of the new time scale.
     * @param new_time_scale the new time scale value
     */
    void time_scale(double new_time_scale);

    /**
     * @brief Set the _time_since_call variable.
     */
    void tick();

private:
    std::chrono::steady_clock::time_point _time_since_call;

    double _time_scale = 1;
};

#endif //ENGINE_TIME_HPP
