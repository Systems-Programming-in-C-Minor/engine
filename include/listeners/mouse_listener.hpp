#ifndef ENGINE_IMOUSELISTENER_HPP
#define ENGINE_IMOUSELISTENER_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

/**
 * @brief Interface for objects wanting to respond to mouse events.
 */
class MouseListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param event_manager The manager which registers listeners and notifies subscribers.
     */
    explicit MouseListener(EventManager &event_manager);

public:
    /**
     * @brief Called whenever the mouse is moved.
     * @param event The desired MouseMovedEvent.
     */
    virtual void on_mouse_moved(const MouseMovedEvent &event) {}

    /**
     * @brief Called each frame when a mouse button is still down.
     * @param event The desired MousePressedEvent.
     */
    virtual void on_mouse_pressed(const MousePressedEvent &event) {}

    /**
     * @brief Called whenever a mouse button is released.
     * @param event The desired MouseReleasedEvent.
     */
    virtual void on_mouse_released(const MouseReleasedEvent &event) {}
};

#endif //ENGINE_IMOUSELISTENER_HPP
