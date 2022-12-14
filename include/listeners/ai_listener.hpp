#ifndef ENGINE_AI_LISTENER_HPP
#define ENGINE_AI_LISTENER_HPP

#include "events.hpp"
#include "../include/managers/event_manager.hpp"


class AIListener {
public:
    explicit AIListener(EventManager &manager);
    virtual void on_target_reached(const AITargetReachedEvent &event) = 0;
};

#endif //ENGINE_AI_LISTENER_HPP