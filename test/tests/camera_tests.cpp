#include <gtest/gtest.h>
#include "camera.hpp"

TEST(CameraTest, GetAndSetBackgroundColor) {
    Camera test_camera;
    Color test_color = { 0,0,0,0 };

    test_camera.set_background_color(test_color);
    EXPECT_EQ(test_color, test_camera.get_background_color());
}