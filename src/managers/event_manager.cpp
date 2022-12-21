#include "../../include/managers/event_manager.hpp"
#include "global.hpp"

void EventManager::register_listener(const Event event, const std::function<void(const IEvent &)> &function) {
    listeners[event].push_back(function);
}

void EventManager::notify(const IEvent &event) {
    const auto scene = &Global::get_instance()->get_engine().get_active_scene();
    for (const auto &function: listeners[event.event]) {
        if (scene != &Global::get_instance()->get_engine().get_active_scene())
            return;
        function(event);
    }
}
