#include "../../include/managers/event_manager.hpp"

void EventManager::register_listener(const std::string &event, const std::function<void(const IEvent &)>& function) {
    listeners[event].push_back(function);
}

void EventManager::notify(const IEvent& event) {
    auto event_name = event.name;

    for (const auto& function: listeners[event_name]) {
        function(event);
    }
}
