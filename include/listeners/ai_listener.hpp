#ifndef ENGINE_AI_LISTENER_HPP
#define ENGINE_AI_LISTENER_HPP

#include "events.hpp"
#include "../include/managers/event_manager.hpp"

/**
 * @brief Interface for objects wanting to respond to AI events.
 */
class AIListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param manager The manager which registers listeners and notifies subscribers.
     */
    explicit AIListener(EventManager &manager);
public:
    /**
     * @brief This method will be called whenever an AI object reaches its target.
     *        Override for implementing the desired behaviour.
     * @param event The desired AITargetReachedEvent.
     */
    virtual void on_target_reached(const AITargetReachedEvent &event) {};
};

#endif //ENGINE_AI_LISTENER_HPP