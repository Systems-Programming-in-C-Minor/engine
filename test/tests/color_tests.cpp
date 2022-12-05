#include <gtest/gtest.h>
#include "color.hpp"

TEST(ColorTest, EqualsTest){
    const Color test_color1 (1,2,3,4);
    const Color test_color2 (1,2,3,4);
    const Color test_color_other(0,0,0,0);
    EXPECT_TRUE(test_color1.equals(test_color2));
    EXPECT_TRUE(test_color1 == test_color2);
    EXPECT_FALSE(test_color1.equals(test_color_other));
    EXPECT_FALSE(test_color1 == test_color_other);
}
