#include <gtest/gtest.h>
#include "uiobjects/Text.hpp"

TEST(TextTest, TextIsInitializedCorrectly)
{
    Text testObject("text", "font", 10, Alignment::center);
    ASSERT_EQ(testObject.getText(), "text");
    ASSERT_EQ(testObject.getFont(), "font");
    ASSERT_EQ(testObject.getSize(), 10);
    ASSERT_EQ(testObject.getAlignment(), Alignment::center);
}

TEST(TextTest, TextIsSetCorrectly)
{
    Text testObject("text", "font", 10, Alignment::center);
    
    testObject.setText("new text");
    testObject.setFont("new font");
    testObject.setSize(20);
    testObject.setAlignment(Alignment::left);

    ASSERT_EQ(testObject.getText(), "new text");
    ASSERT_EQ(testObject.getFont(), "new font");
    ASSERT_EQ(testObject.getSize(), 20);
    ASSERT_EQ(testObject.getAlignment(), Alignment::left);
}
