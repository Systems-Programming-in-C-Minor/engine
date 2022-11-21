#include <gtest/gtest.h>
#include "components/colliders/boxcollider.hpp"

TEST(BoxcolliderTest, GetAndSetWidth){
    auto test_box_collider = new BoxCollider();
    double test_value = 1;
    test_box_collider->set_width(test_value);

    EXPECT_EQ(1.0, test_box_collider->get_width());
}

TEST(BoxcolliderTest, GetAndSetHeight){
    auto test_box_collider = new BoxCollider();
    double test_value = 1.0;
    test_box_collider->set_height(test_value);
    EXPECT_EQ(1.0, test_box_collider->get_height());
}