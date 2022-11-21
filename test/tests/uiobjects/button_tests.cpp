#include <gtest/gtest.h>
#include "uiobjects/button.hpp"

#define test_button Button("name", "tag", 10, 10, true)

class TestButton : public UIObject {
};

TEST(ButtonTests, TestButtonClick)
{
    auto button = test_button;
    ASSERT_TRUE(button.get_interactable());

    int clicks = 0;
    button.on_click([&clicks](){
        clicks++;
    });
    button.click();
    ASSERT_EQ(clicks, 1);
}