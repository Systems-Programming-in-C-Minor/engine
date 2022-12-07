#include "../include/listeners/mouse_listener.hpp"
#include "global.hpp"

MouseListener::MouseListener() {
    Global::get_instance()->get_engine()
            .event_manager->register_listener(MouseMoved, [this](const IEvent &event) {
                on_mouse_moved(dynamic_cast<const MouseMovedEvent &>(event));
            });
    Global::get_instance()->get_engine()
            .event_manager->register_listener(MousePressed, [this](const IEvent &event) {
                on_mouse_pressed(dynamic_cast<const MousePressedEvent &>(event));
            });
    Global::get_instance()->get_engine()
            .event_manager->register_listener(MouseReleased, [this](const IEvent &event) {
                on_mouse_released(dynamic_cast<const MouseReleasedEvent &>(event));
            });
}
