#include <gtest/gtest.h>
#include "components/sprite.hpp"
#include "components/animator.hpp"
#include "gameobject.hpp"
#include "global.hpp"
#include "../../mocks/mock_engine.hpp"

#define test_game_object GameObject("TestGameObject", "TestTag")

TEST(AnimatorTest, Animate) {
    auto game_object = test_game_object;
    auto mock_engine = std::make_unique<MockEngine>();
    Global::get_instance()->set_engine(std::move(mock_engine));

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 10);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play();

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    // Tick and check sprite 2
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    // Last frame
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
}

TEST(AnimatorTest, AnimateFPS) {
    auto game_object = test_game_object;
    auto mock_engine = std::make_unique<MockEngine>();
    Global::get_instance()->set_engine(std::move(mock_engine));

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 10);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play();

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    // Tick and check sprite 2
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    // Last frame
    game_object.tick();

    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
}

TEST(AnimatorTest, AnimateWithLoop) {
    auto game_object = test_game_object;
    auto mock_engine = std::make_unique<MockEngine>();

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 10);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play(true);

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    // Tick and check sprite 2
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    // Last frame
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    for (int i = 0; i < 2; ++i) {
        // Check sprite 1
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));

        // Tick and check sprite 2
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));

        // Last frame
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
}

TEST(AnimatorTest, AnimateAndStop) {
    auto game_object = test_game_object;
    auto mock_engine = std::make_unique<MockEngine>();

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 10);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play(true);

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    // Tick and check sprite 2
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    // Stop
    animator->stop();

    for (int i = 0; i < 5; i++) {
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
}

TEST(AnimatorTest, AnimateWithoutPlay) {
    auto game_object = test_game_object;
    auto mock_engine = std::make_unique<MockEngine>();

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2};
    const auto animator = std::make_shared<Animator>(sprites, 20);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    for (int i = 0; i < 5; i++) {
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
}


TEST(AnimatorTest, AnimateNotActive) {
    auto game_object = test_game_object;
    auto mock_engine = std::make_unique<MockEngine>();

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2};
    const auto animator = std::make_shared<Animator>(sprites, 20);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play();

    animator->set_active(false);

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(120));

    for (int i = 0; i < 5; i++) {
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
}


