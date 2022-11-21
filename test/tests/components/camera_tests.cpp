#include <gtest/gtest.h>
#include "components/camera.hpp"

TEST(CameraTest, GetAndSetBackgroundColor){
    Camera test_camera {1280, 720};
    Color test_color = {0,0,0,0};

    test_camera.set_background_color(test_color);
    EXPECT_EQ(test_color, test_camera.get_background_color());
}

TEST(CameraTest, GetAndSetAspectWidth){
    Camera test_camera {1280, 720};
    int test_value = 9999;

    test_camera.set_aspect_width(test_value);
    EXPECT_EQ(9999, test_camera.get_aspect_width());
}

TEST(CameraTest, GetAndSetAspectHeight){
    Camera test_camera {1280, 720};
    int test_value = 9999;

    test_camera.set_aspect_height(test_value);
    EXPECT_EQ(9999, test_camera.get_aspect_height());
}

