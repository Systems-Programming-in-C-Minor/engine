#include <gtest/gtest.h>
#include "components/colliders/polygoncollider.hpp"
#include <vector>
#include "vector2d.hpp"

TEST(PolygonColliderTest, GetPoints){
    std::vector<Vector2d> test_points;
    const Vector2d point {0.0, 1.0};
    test_points.push_back(point);
    const PolygonCollider test_polygon_collider {test_points};

    EXPECT_EQ(test_points, test_polygon_collider.get_points());
}

TEST(PolygonColliderTest, GetICP_Test){
    PolygonCollider test_polygon_collider {"test"};
    test_polygon_collider.set_ignore_collision_physics(true);
    EXPECT_TRUE(test_polygon_collider.get_ignore_collision_physics());
}
