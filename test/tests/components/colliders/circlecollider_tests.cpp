#include <gtest/gtest.h>
#include "components/colliders/circlecollider.hpp"

TEST(CircleColliderTest, GetAndSetWidth){
    auto test_circle_collider = new CircleCollider();
    double test_value = 1;
    test_circle_collider->set_radius(test_value);

    EXPECT_EQ(1.0, test_circle_collider->get_radius());
}