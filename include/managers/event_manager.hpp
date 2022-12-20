
#ifndef ENGINE_EVENT_MANAGER_HPP
#define ENGINE_EVENT_MANAGER_HPP

#include <memory>
#include <map>
#include <vector>
#include <functional>
#include "../interfaces/ievent.hpp"

/**
 * @brief Manager which handles events.
 */
class EventManager {
public:
    /**
     * Method which registers a listener.
     * @param event The event which will be registered.
     * @param function The function which will be mapped to the given event.
     */
    void register_listener(Event event, const std::function<void(const IEvent &event)>& function);

    /**
     * Method which notifies all registered listeners.
     * @param event The event of which the registered function will be called.
     */
    void notify(const IEvent& event);

private:
    std::map<Event, std::vector<std::function<void(const IEvent &event)>>> listeners;
};

#endif //ENGINE_EVENT_MANAGER_HPP
