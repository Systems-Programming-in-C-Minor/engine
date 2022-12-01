
#ifndef ENGINE_EVENT_MANAGER_HPP
#define ENGINE_EVENT_MANAGER_HPP

#include <memory>
#include <map>
#include "../interfaces/ievent.hpp"
#include <vector>
#include <functional>

class EventManager {
public:
    void register_listener(const std::string &event, const std::function<void(const IEvent &event)> &function);

    void notify(IEvent event);

private:
    std::map<std::string, std::vector<const std::function<void(const IEvent &event)> &>> listeners;
};

#endif //ENGINE_EVENT_MANAGER_HPP
