#ifndef ENGINE_UIOBJECT_LISTENER_HPP
#define ENGINE_UIOBJECT_LISTENER_HPP

#include "../include/managers/event_manager.hpp"
#include "events.hpp"

class UiObjectListener {
protected:
    explicit UiObjectListener(EventManager &event_manager);

public:
    virtual void on_uiobject_pressed(const UiObjectPressedEvent &event) {}

    virtual void on_uiobject_released(const UiObjectReleasedEvent &event) {}
};

#endif //ENGINE_UIOBJECT_LISTENER_HPP
