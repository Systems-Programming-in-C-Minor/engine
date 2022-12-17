#ifndef ENGINE_IKEYLISTENER_HPP
#define ENGINE_IKEYLISTENER_HPP


#include "../include/managers/event_manager.hpp"
#include "events.hpp"

class KeyListener {
protected:
    explicit KeyListener(EventManager &event_manager);

public:
    virtual void on_key_pressed(const KeyPressedEvent &event) {};

    virtual void on_key_hold(const KeyHoldEvent &event) {};

    virtual void on_key_released(const KeyReleasedEvent &event) {};
};

#endif //ENGINE_IKEYLISTENER_HPP
