#include <gtest/gtest.h>
#include "components/colliders/circlecollider.hpp"

TEST(CircleColliderTest, GetWidth){
    constexpr double test_value = 1.0;
	const CircleCollider test_circle_collider {test_value};

    EXPECT_EQ(1.0, test_circle_collider.get_radius());
}