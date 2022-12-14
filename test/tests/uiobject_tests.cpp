#include <gtest/gtest.h>
#include "uiobject.hpp"

#define test_ui_object UIObject("name", "tag", true, Transform{Vector2d{0.f, 0.f}, 0.0f, 0.5f}, 10, 10)

TEST(UIObjectTest, TestGetWidthHeight)
{
    auto ui_object = test_ui_object;
    ASSERT_EQ(10, ui_object.get_width());
    ASSERT_EQ(10, ui_object.get_height());
}

TEST(UIObjectTest, TestSetWidthHeight)
{
    auto ui_object = test_ui_object;
    ui_object.set_width(20);
    ui_object.set_height(30);
    ASSERT_EQ(20, ui_object.get_width());
    ASSERT_EQ(30, ui_object.get_height());
}
