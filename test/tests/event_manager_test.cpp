#include <gtest/gtest.h>
#include "../mocks/mock_event_manager.hpp"
#include "../mocks/mock_mouse_moved_event.hpp"

#define test_event_manager EventManager()
#define test_event MouseMovedEvent()

TEST(EventManagerTest, Register) {
    auto event_manager = test_event_manager;
    auto event = test_event;

    void (*function)() {};

    event_manager.register_listener(typeid(event).name(), function);

//     How to test?
//    EXPECT_CALL(event_manager, notify(event));
}
