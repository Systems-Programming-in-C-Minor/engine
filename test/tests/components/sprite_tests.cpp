#include <gtest/gtest.h>

#include "global.hpp"
#include "components/sprite.hpp"
#include "../../mocks/mock_renderer.hpp"
#include "../../mocks/mock_engine.hpp"

#define testSprite Sprite("/path/to", Color(0,0,0,0), false, false, 1, 1)

TEST(ComponentTest, Render) {
    auto mock_engine = std::make_unique<MockEngine>();
    auto renderer = std::make_shared<MockRenderer>();

    EXPECT_CALL(*mock_engine, get_renderer())
		.Times(1)
		.WillOnce(testing::Return(renderer));

    Global::get_instance()->set_engine(std::move(mock_engine));
    auto sprite = testSprite;
    

    EXPECT_CALL(*renderer, render_sprite(testing::_, testing::_, testing::_, false))
            .Times(1);

    sprite.render(false);

    Global::get_instance()->set_engine(nullptr);
}
