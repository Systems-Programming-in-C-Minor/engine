#include "../../include/managers/event_manager.hpp"

void EventManager::register_listener(const Event event, const std::function<void(const IEvent &)>& function) {
    listeners[event].push_back(function);
}

void EventManager::notify(const IEvent& event) {
    for (const auto& function: listeners[event.event]) {
        function(event);
    }
}
