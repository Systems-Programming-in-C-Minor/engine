#include <gtest/gtest.h>
#include "time.hpp"
#include <thread>

using namespace std::chrono;

TEST(TimeTest, DeltaTimeTest) {
    for (int i = 0; i < 2; ++i) {
        Time test_time;
        test_time.tick();

        std::this_thread::sleep_for(0.3s);
        auto res = test_time.delta_time();

        EXPECT_NEAR(0.3, res, 0.02);
    }

    for (int i = 0; i < 2; ++i) {
        Time test_time;
        test_time.tick();

        std::this_thread::sleep_for(0.1s);
        auto res = test_time.delta_time();

        EXPECT_NEAR(0.1, res, 0.02);
    }
}
