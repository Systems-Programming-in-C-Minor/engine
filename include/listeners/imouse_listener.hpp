#ifndef ENGINE_IMOUSELISTENER_HPP
#define ENGINE_IMOUSELISTENER_HPP

#include "enums/mouse_input.hpp"

class IMouseListener {

    virtual void on_mouse_moved() = 0;

    virtual void on_mouse_clicked(MouseInput button) = 0;

    virtual void on_mouse_pressed(MouseInput button) = 0;

    virtual void on_mouse_released(MouseInput button) = 0;

};

#endif //ENGINE_IMOUSELISTENER_HPP
