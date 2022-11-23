#include <gtest/gtest.h>
#include "components/colliders/boxcollider.hpp"

TEST(BoxcolliderTest, GetWidth){
    constexpr double test_value = 1.0;
    const BoxCollider test_box_collider {test_value, 0};

    EXPECT_EQ(1.0, test_box_collider.get_width());
}

TEST(BoxcolliderTest, GetHeight){
    constexpr double test_value = 1.0;
    const BoxCollider test_box_collider {0, test_value};
    EXPECT_EQ(1.0, test_box_collider.get_height());
}