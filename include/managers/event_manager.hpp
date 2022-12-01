
#ifndef ENGINE_EVENT_MANAGER_HPP
#define ENGINE_EVENT_MANAGER_HPP

#include "memory"
#include "map"
#include "../interfaces/ievent.hpp"
#include "vector"

class EventManager {
public:
    void register_listener(const std::string& event, void(*function)());

    void notify(IEvent event);

private:
    std::map<std::string, std::vector<void(*)()>> listeners;
};

#endif //ENGINE_EVENT_MANAGER_HPP
