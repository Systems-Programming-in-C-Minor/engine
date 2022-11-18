#ifndef ENGINE_ANIMATOR_HPP
#define ENGINE_ANIMATOR_HPP

#include "component.hpp"
#include "memory"
#include "vector"
#include "sprite.hpp"
#include "interfaces/itickable.hpp"

typedef std::vector<std::shared_ptr<Sprite>> Sprites;

class Animator : public Component, public ITickable {
public:

    Animator(Sprites sprites, int fps);

    void play(bool looping = false);

    void stop();

    void tick(GameObject &object) override;

private:
    const int _fps;
    const Sprites _sprites;

    int _current = 0;
    bool _play = false;
    bool _loop = false;
    int _ticks_since_last_animate = -1;

    [[nodiscard]] int animate_per_ticks() const;
};

#endif //ENGINE_ANIMATOR_HPP
