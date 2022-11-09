#include <gtest/gtest.h>
#include "Engine.hpp"

TEST(EngineTest, ReturnsHelloWorld) {
    EXPECT_EQ(hello(), "Hello, World!");
}
