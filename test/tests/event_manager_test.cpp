#include <gtest/gtest.h>

#include <utility>
#include "managers/event_manager.hpp"
#include "events.hpp"

class TestEvent1 : public IEvent {
public:
    std::string some_data;
    explicit TestEvent1(std::string some_data) : IEvent(MousePressed), some_data(std::move(some_data)) {}
};

class TestEvent2 : public IEvent {
public:
    TestEvent2() : IEvent(MouseReleased) {}
};

#define test_event_manager EventManager()

TEST(EventManagerTest, CallCorrectEvents) {
    auto event_manager = test_event_manager;
    auto event1 = TestEvent1("abc");
    auto event2 = TestEvent2();

    auto listener1_counter = 0;
    auto listener2_counter = 0;

    event_manager.register_listener(MousePressed, [&listener1_counter](auto event){
        listener1_counter++;
    });

    event_manager.register_listener(MousePressed, [&listener1_counter](auto event){
        listener1_counter++;
    });

    event_manager.register_listener(MouseReleased, [&listener2_counter](auto event){
        listener2_counter++;
    });

    event_manager.notify(event1);

    EXPECT_EQ(listener1_counter, 2);
    EXPECT_EQ(listener2_counter, 0);

    listener1_counter = 0;
    listener2_counter = 0;

    event_manager.notify(event2);

    EXPECT_EQ(listener1_counter, 0);
    EXPECT_EQ(listener2_counter, 1);
}

TEST(EventManagerTest, UseActualEvent) {
    auto event_manager = test_event_manager;
    auto event1 = TestEvent1("abc");

    auto listener1_counter = 0;

    event_manager.register_listener(MousePressed, [&listener1_counter](const IEvent& event){
        auto test_event = dynamic_cast<const TestEvent1&>(event);
        EXPECT_EQ(test_event.some_data, "abc");
        listener1_counter++;
    });

    event_manager.notify(event1);

    EXPECT_EQ(listener1_counter, 1);
}
