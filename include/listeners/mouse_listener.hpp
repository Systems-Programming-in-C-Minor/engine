#ifndef ENGINE_IMOUSELISTENER_HPP
#define ENGINE_IMOUSELISTENER_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

class MouseListener {
protected:
    explicit MouseListener(EventManager &event_manager);

public:
    virtual void on_mouse_moved(const MouseMovedEvent &event) {};

    virtual void on_mouse_pressed(const MousePressedEvent &event) {};

    virtual void on_mouse_released(const MouseReleasedEvent &event) {};
};

#endif //ENGINE_IMOUSELISTENER_HPP
