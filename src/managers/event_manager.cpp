#include "../../include/managers/event_manager.hpp"

void EventManager::register_listener(const std::string &event, void (*function)()) {
    auto listener = listeners.find(event);
    if (listener == listeners.end()) {
        auto functions = {function};
        listeners.emplace(event, functions);
        return;
    }

    listener->second.emplace_back(function);
}

void EventManager::notify(IEvent event) {
    auto event_name = typeid(event).name();
    auto listener = listeners.find(event_name);

    if (listener == listeners.end())
        return;

    for (const auto function: listener->second)
        function();
}
