#ifndef ENGINE_IKEYLISTENER_HPP
#define ENGINE_IKEYLISTENER_HPP

#include "enums/key.hpp"
#include "../include/managers/event_manager.hpp"

class KeyListener {

private:
    KeyListener(EventManager manager);

public:
    virtual void on_key_pressed(Key key) = 0;

    virtual void on_key_released(Key key) = 0;

};

#endif //ENGINE_IKEYLISTENER_HPP
