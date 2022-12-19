#include "components/animator.hpp"
#include "gameobject.hpp"
#include "global.hpp"

Animator::Animator(Sprites sprites, const int fps) : _sprites(std::move(sprites)), _fps(fps) {}

Animator::Animator(Sprites sprites, int fps, bool start_playing, bool looping) : Animator(std::move(sprites), fps) {
    if (start_playing)
        play(looping);
}

void Animator::play(bool looping) {
    _loop = looping;
    _play = true;
}

void Animator::stop() {
    _loop = false;
    _play = false;
    _current = 0;
}

bool Animator::should_animate() {
    const auto delta_time = Global::get_instance()->get_delta_time();
    _time_since_last_animate += delta_time;
    if (_time_since_last_animate > (1000.0 / _fps)) { // Time at least necessary for sprite change
        _time_since_last_animate = 0;
        return true;
    }
    return false;
}

void Animator::tick(GameObject &object) {
    if (!active || !_play)
        return;

    if (!should_animate()) {
        return;
    }

    object.remove_component(object.get_component<Sprite>());

    _current++;
    if (_current >= _sprites.size()) {
        _current = 0;
        if (!_loop)
            stop();
    }

    object.add_component(_sprites[_current]);

    _time_since_last_animate = 0;
}
