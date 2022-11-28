#include <gtest/gtest.h>
#include "time.hpp"
#include <thread>

TEST(TimeTest, DeltaTimeTest5x){
    for(int i; i<5; ++i){
        Time test_time;
        test_time.tick();
        std::this_thread::sleep_for(1s);

        auto res = test_time.delta_time();

        EXPECT_NEAR(1, res, 0.2);
    }
}

TEST(TimeTest, DeltaTimeTest10x){
    for(int i; i<10; ++i){
        Time test_time;
        test_time.tick();
        std::this_thread::sleep_for(0.5s);

        auto res = test_time.delta_time();

        EXPECT_NEAR(0.5, res, 0.1);
    }
}