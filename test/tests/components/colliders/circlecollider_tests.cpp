#include <gtest/gtest.h>
#include "components/colliders/circlecollider.hpp"

TEST(CircleColliderTest, GetWidth) {
    constexpr float test_value = 1.0f;
    const CircleCollider test_circle_collider{Vector2d{1.f, 1.f}, test_value};

    EXPECT_EQ(1.0, test_circle_collider.get_radius());
}