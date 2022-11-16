#include <gtest/gtest.h>
#include "components/sprite.hpp"
#include "../../mocks/mock_renderer.hpp"

#define testSprite Sprite("/path/to", Color(0,0,0,0), false, false, 1, 1)

TEST(ComponentTest, Render) {
    auto sprite = testSprite;
    auto renderer = MockRenderer();

    EXPECT_CALL(renderer, render_sprite(testing::_, testing::_, false))
            .Times(1);

    sprite.render(renderer, false);
}
