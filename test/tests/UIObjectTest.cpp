#include <gtest/gtest.h>
#include "UIObject.hpp"

TEST(UIObjectTest, PropertiesAreInitializedCorrectly)
{
    UIObject testObject(10.0, 10.0);
    EXPECT_EQ(testObject.getWidth(), 10.0);
    EXPECT_EQ(testObject.getHeight(), 10.0);
}

TEST(UIObjectTest, PropertiesAreSetCorrectly)
{
    UIObject testObject(10.0, 10.0);
    testObject.setWidth(20.0);
    testObject.setHeight(20.0);
    EXPECT_EQ(testObject.getWidth(), 20.0);
    EXPECT_EQ(testObject.getHeight(), 20.0);
}
