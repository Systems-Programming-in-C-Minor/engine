#include <gtest/gtest.h>
#include "components/colliders/collider.hpp"

#define test_collider Collider()

TEST(ColliderTest, GetAndSetIgnorePhysics){
    auto collider = test_collider;
    EXPECT_FALSE(collider.get_ignore_collision_physics());
    collider.set_ignore_collision_physics(true);
    EXPECT_TRUE(collider.get_ignore_collision_physics());
}