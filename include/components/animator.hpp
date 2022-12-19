#ifndef ENGINE_ANIMATOR_HPP
#define ENGINE_ANIMATOR_HPP

#include "component.hpp"
#include "memory"
#include "vector"
#include "sprite.hpp"
#include "interfaces/itickable.hpp"

using Sprites = std::vector<std::shared_ptr<Sprite>>;

/**
 * @brief A component which can play animated sequences of sprites.
 */
class Animator : public Component, public ITickable {
public:

    Animator(Sprites sprites, int fps);

    Animator(Sprites sprites, int fps, bool start_playing, bool looping = false);

    /**
     * @brief Start the animation on the next tick.
     * @param looping when the animation is finished start it again automatically.
     */
    void play(bool looping = false);

    /**
     * @brief stop the animation.
     */
    void stop();

    /**
     * @brief Run the animation every tick.
     * @details First determine if the Sprite should be swapped this tick. If so, do so.
     * @param object the GameObject on which the action is performed.
     */
    void tick(GameObject &object) override;

private:
    const int _fps;
    const Sprites _sprites;

    unsigned int _current = 0;
    bool _play = false;
    bool _loop = false;
    double _time_since_last_animate = -1;

    /**
     * @brief Determines how many ticks there are between swaps.
     * @return int  number of ticks between sprite swap.
     */
    [[nodiscard]] bool should_animate();
};

#endif //ENGINE_ANIMATOR_HPP
