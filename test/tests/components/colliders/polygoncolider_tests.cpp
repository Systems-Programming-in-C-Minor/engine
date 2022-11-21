#include <gtest/gtest.h>
#include "components/colliders/polygoncollider.hpp"
#include <vector>
#include "vector2d.hpp"



TEST(PolygonColliderTest, GetAndSetPoints){
    PolygonCollider test_polygon_collider {};
    std::vector<Vector2d> test_points;
    Vector2d point {0.0, 1.0};
    test_points.push_back(point);

    test_polygon_collider.set_points(test_points);
    EXPECT_EQ(test_points, test_polygon_collider.get_points());
}

TEST(PolygonColliderTest, GetAndSetICP_Test){
    PolygonCollider test_polygon_collider {};
    test_polygon_collider.set_ignore_collision_physics(true);
    EXPECT_TRUE(test_polygon_collider.get_ignore_collision_physics());
}

TEST(PolygonColliderTest, ConstructorTest){
    std::vector<Vector2d> test_points2;
    Vector2d point {1.0, 2.0};
    test_points2.push_back(point);
    PolygonCollider test_polygon_collider2 {test_points2};

    EXPECT_EQ(test_points2, test_polygon_collider2.get_points());
}
