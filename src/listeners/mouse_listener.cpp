#include "../include/listeners/uiobject_listener.hpp"

UiObjectListener::UiObjectListener(EventManager &event_manager) {
    event_manager.register_listener(UiObjectPressed, [this](const IEvent &event) {
        on_uiobject_pressed(dynamic_cast<const UiObjectPressedEvent &>(event));
    });
    event_manager.register_listener(UiObjectReleased, [this](const IEvent &event) {
        on_uiobject_released(dynamic_cast<const UiObjectReleasedEvent &>(event));
    });
}
