#ifndef ENGINE_IMOUSELISTENER_HPP
#define ENGINE_IMOUSELISTENER_HPP

#include "enums/mouse_input.hpp"
#include "../include/managers/event_manager.hpp"

class MouseListener {

private:
    MouseListener(EventManager manager);

public:
    virtual void on_mouse_moved() = 0;

    virtual void on_mouse_clicked(MouseInput button) = 0;

    virtual void on_mouse_pressed(MouseInput button) = 0;

    virtual void on_mouse_released(MouseInput button) = 0;

};

#endif //ENGINE_IMOUSELISTENER_HPP
