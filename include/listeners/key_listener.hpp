#ifndef ENGINE_IKEYLISTENER_HPP
#define ENGINE_IKEYLISTENER_HPP


#include "../include/managers/event_manager.hpp"
#include "events.hpp"

class KeyListener {

public:
    explicit KeyListener(EventManager &event_manager);

    virtual void on_key_pressed(const KeyPressedEvent &event) = 0;

    virtual void on_key_released(const KeyReleasedEvent &event) = 0;
};

#endif //ENGINE_IKEYLISTENER_HPP
