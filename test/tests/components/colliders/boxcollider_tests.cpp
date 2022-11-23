#include <gtest/gtest.h>
#include "components/colliders/boxcollider.hpp"

TEST(BoxcolliderTest, GetWidth){
    double test_value = 1.0;
    BoxCollider test_box_collider {test_value, 0};

    EXPECT_EQ(1.0, test_box_collider.get_width());
}

TEST(BoxcolliderTest, GetHeight){
    double test_value = 1.0;
    BoxCollider test_box_collider {0, test_value};
    EXPECT_EQ(1.0, test_box_collider.get_height());
}