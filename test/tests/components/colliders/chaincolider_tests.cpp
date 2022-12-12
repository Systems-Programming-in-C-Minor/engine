#include <gtest/gtest.h>
#include "components/colliders/chaincollider.hpp"
#include <vector>
#include "vector2d.hpp"

TEST(ChainColliderTest, GetPoints){
    std::vector<Vector2d> test_points;
    const Vector2d point {0.0, 1.0};
    test_points.push_back(point);
    const ChainCollider test_polygon_collider {test_points};

    EXPECT_EQ(test_points, test_polygon_collider.get_points());
}