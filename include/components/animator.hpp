#ifndef ENGINE_ANIMATOR_HPP
#define ENGINE_ANIMATOR_HPP

#include "component.hpp"
#include "memory"
#include "vector"
#include "sprite.hpp"
#include "interfaces/itickable.hpp"

using Sprites = std::vector<std::shared_ptr<Sprite>>;

class Animator : public Component, public ITickable {
public:

    Animator(Sprites sprites, int fps);

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
     * @param object
     */
    void tick(GameObject &object) override;

private:
    const int _fps;
    const Sprites _sprites;

    unsigned int _current = 0;
    bool _play = false;
    bool _loop = false;
    int _ticks_since_last_animate = -1;

    /**
     * @brief Determines how many ticks there are between swaps.
     * @return int  number of ticks between sprite swap.
     */
    [[nodiscard]] int animate_per_ticks() const;
};

#endif //ENGINE_ANIMATOR_HPP