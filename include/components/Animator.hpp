//
// Created by lars on 13-11-22.
//

#ifndef ENGINE_ANIMATOR_HPP
#define ENGINE_ANIMATOR_HPP

#include "Component.hpp"
#include "memory"
#include "vector"
#include "Sprite.hpp"

class Animator : public Component {
public:
    typedef vector<unique_ptr<Sprite>> Sprites;

    Animator(Sprites _sprites, const int fps);

    void play(bool looping = false);

    void stop();

protected:
    void tick();

private:
    const int fps;
    const Sprites sprites;

    int current = 0;
    bool _play = false;
    bool loop = false;
    int ticks_since_last_animate = -1;

    int animatePerTicks() const;
};

#endif //ENGINE_ANIMATOR_HPP
