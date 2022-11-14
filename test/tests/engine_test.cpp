#include <gtest/gtest.h>
#include "engine.hpp"

TEST(EngineTest, ReturnsHelloWorld) {
    EXPECT_EQ(hello(), "Hello, World!");
}
