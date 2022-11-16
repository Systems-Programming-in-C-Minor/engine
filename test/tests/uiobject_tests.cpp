#include <gtest/gtest.h>
#include "uiobject.hpp"

#define test_ui_object UIObject("name", "tag", 10, 10)

class TestUIObject : public UIObject {
};

TEST(UIObjectTest, TestGetProperties)
{
    auto ui_object = test_ui_object;
    ASSERT_EQ(10, test_ui_object.get_width());
    ASSERT_EQ(10, test_ui_object.get_height());
}

TEST(UIObjectTest, TestSetProperties)
{
    auto ui_object = test_ui_object;
    ui_object.set_height(20);
    ui_object.set_width(20);
    ASSERT_EQ(20, test_ui_object.get_width());
    ASSERT_EQ(20, test_ui_object.get_height());
}

