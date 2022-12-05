
#ifndef ENGINE_EVENT_MANAGER_HPP
#define ENGINE_EVENT_MANAGER_HPP

#include <memory>
#include <map>
#include <vector>
#include <functional>
#include "../interfaces/ievent.hpp"

class EventManager {
public:
    void register_listener(Event event, const std::function<void(const IEvent &event)>& function);

    void notify(const IEvent& event);

private:
    std::map<Event, std::vector<std::function<void(const IEvent &event)>>> listeners;
};

#endif //ENGINE_EVENT_MANAGER_HPP
