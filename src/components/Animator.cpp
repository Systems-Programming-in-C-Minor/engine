//
// Created by lars on 13-11-22.
//

#include "components/Animator.hpp"

Animator::Animator(Animator::Sprites _sprites, const int fps) : sprites(std::move(_sprites)), fps(fps) {}

void Animator::play(bool looping) {
    loop = looping;
    _play = true;
}

void Animator::stop() {
    loop = false;
    _play = false;
    current = 0;
}

void Animator::tick() {
    if (!active || !_play)
        return;

    if (ticks_since_last_animate >= 0 && ticks_since_last_animate < animatePerTicks()) {
        ticks_since_last_animate++;
        return;
    }

    // TODO replace current sprite in game object
    // Waiting on more game object logic to be implemented

    if (!loop && current >= sprites.size())
        stop();

    current++;

    ticks_since_last_animate = 0;
}

int Animator::animatePerTicks() const {
    // TODO get the TICKS_PER_SECOND dynamically
    const int TICKS_PER_SECOND = 20;
    return TICKS_PER_SECOND / fps;
}