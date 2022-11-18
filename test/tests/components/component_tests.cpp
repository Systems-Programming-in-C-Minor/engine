#include <gtest/gtest.h>
#include "components/component.hpp"

class TestComponent : public Component {
};

TEST(ComponentTest, IsActiveUpdated) {
    auto component = TestComponent();
    component.set_active(true);
    EXPECT_TRUE(component.get_active());
    component.set_active(false);
    EXPECT_FALSE(component.get_active());
}
