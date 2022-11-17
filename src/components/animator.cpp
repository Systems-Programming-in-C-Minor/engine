#include "components/animator.hpp"

#include <utility>

Animator::Animator(Animator::Sprites sprites, const int fps) : _sprites(std::move(sprites)), _fps(fps) {}

void Animator::play(bool looping) {
    _loop = looping;
    _play = true;
}

void Animator::stop() {
    _loop = false;
    _play = false;
    _current = 0;
}

int Animator::animate_per_ticks() const {
    // TODO get the TICKS_PER_SECOND dynamically
    const int TICKS_PER_SECOND = 20;
    return TICKS_PER_SECOND / _fps;
}

void Animator::tick(GameObject &object) {
    if (!active || !_play)
        return;

    if (_ticks_since_last_animate >= 0 && _ticks_since_last_animate < animate_per_ticks()) {
        _ticks_since_last_animate++;
        return;
    }

    object.remove_component(object.get_component<Sprite>());

    if (!_loop && _current >= _sprites.size())
        stop();
    else if (_current >= _sprites.size())
        _current = 0;
    else
        _current++;

    // TODO fix add component for test
    // object.add_component(_sprites[_current]);

    _ticks_since_last_animate = 0;
}