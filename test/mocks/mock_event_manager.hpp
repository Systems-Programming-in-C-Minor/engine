
#ifndef ENGINE_MOCK_EVENT_MANAGER_HPP
#define ENGINE_MOCK_EVENT_MANAGER_HPP

#include <gmock/gmock-function-mocker.h>
#include "managers/event_manager.hpp"

class MockEventManager : public EventManager {
public:
    MOCK_METHOD(void, register_listener, (const std::string &event, void (*function)()));
    MOCK_METHOD(void, notify, (IEvent event));
};

#endif //ENGINE_MOCK_EVENT_MANAGER_HPP
