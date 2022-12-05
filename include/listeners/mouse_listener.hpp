#ifndef ENGINE_IMOUSELISTENER_HPP
#define ENGINE_IMOUSELISTENER_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

class MouseListener {

private:
    explicit MouseListener(EventManager &manager);

public:
    virtual void on_mouse_moved(const MouseMovedEvent &event) = 0;

    virtual void on_mouse_clicked(const MouseClickedEvent &event) = 0;

    virtual void on_mouse_pressed(const MousePressedEvent &event) = 0;

    virtual void on_mouse_released(const MouseReleasedEvent &event) = 0;

};

#endif //ENGINE_IMOUSELISTENER_HPP
