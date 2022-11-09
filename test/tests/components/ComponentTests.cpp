#include <gtest/gtest.h>
#include "components/Component.hpp"

class TestComponent : public Component {
};

TEST(ComponentTest, IsActiveUpdated) {
    auto component = TestComponent();
    component.setActive(true);
    EXPECT_TRUE(component.getActive());
    component.setActive(false);
    EXPECT_FALSE(component.getActive());
}
