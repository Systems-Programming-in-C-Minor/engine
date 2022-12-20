#ifndef ENGINE_UIOBJECT_LISTENER_HPP
#define ENGINE_UIOBJECT_LISTENER_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

/**
 * @brief Interface for objects wanting to respond to ui object events.
 */
class UiObjectListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param event_manager The manager which registers listeners and notifies subscribers.
     */
    explicit UiObjectListener(EventManager &event_manager);

public:
    /**
     * @brief Called whenever a ui object is pressed.
     * @param event The desired UiObjectPressedEvent.
     */
    virtual void on_uiobject_pressed(const UiObjectPressedEvent &event) {}

    /**
     * @brief Called whenever a ui object is released.
     * @param event The desired UiObjectReleasedEvent.
     */
    virtual void on_uiobject_released(const UiObjectReleasedEvent &event) {}
};

#endif //ENGINE_UIOBJECT_LISTENER_HPP
