#include <gtest/gtest.h>
#include "components/sprite.hpp"
#include "components/animator.hpp"
#include "gameobject.hpp"

#define test_game_object GameObject("TestGameObject", "TestTag")


TEST(AnimatorTest, Animate) {
    auto game_object = test_game_object;

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 20);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play();

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);

    // Tick and check sprite 2
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);

    // Last frame
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);

    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
}

TEST(AnimatorTest, AnimateFPS) {
    auto game_object = test_game_object;

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 1);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play();

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);

    // Tick and check sprite 2
    for (int i = 0; i < 20; ++i)
        game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);

    // Last frame
    for (int i = 0; i < 20; ++i)
        game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);

    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
}

TEST(AnimatorTest, AnimateWithLoop) {
    auto game_object = test_game_object;

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 20);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play(true);

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);

    // Tick and check sprite 2
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);

    // Last frame
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);

    for (int i = 0; i < 5; ++i) {
        // Check sprite 1
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);

        // Tick and check sprite 2
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);

        // Last frame
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_3);
    }

    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
}

TEST(AnimatorTest, AnimateAndStop) {
    auto game_object = test_game_object;

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);
    const auto sprite_3 = std::make_shared<Sprite>("/path/to", Color(3, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2, sprite_3};
    const auto animator = std::make_shared<Animator>(sprites, 20);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    animator->play(true);

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);

    // Tick and check sprite 2
    game_object.tick();
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);

    // Stop
    animator->stop();

    for (int i = 0; i < 5; i++) {
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_2);
    }
}

TEST(AnimatorTest, AnimateWithoutPlay) {
    auto game_object = test_game_object;

    const auto sprite_1 = std::make_shared<Sprite>("/path/to", Color(1, 0, 0, 0), false, false, 1, 1);
    const auto sprite_2 = std::make_shared<Sprite>("/path/to", Color(2, 0, 0, 0), false, false, 1, 1);

    const Sprites sprites{sprite_1, sprite_2};
    const auto animator = std::make_shared<Animator>(sprites, 20);

    game_object.add_component(animator);
    game_object.add_component(sprite_1);

    // Check sprite 1
    EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);

    for (int i = 0; i < 5; i++) {
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    }
}


TEST(AnimatorTest, AnimateNotActive) {
    auto game_object = test_game_object;

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

    for (int i = 0; i < 5; i++) {
        game_object.tick();
        EXPECT_EQ(game_object.get_component<Sprite>(), sprite_1);
    }
}
