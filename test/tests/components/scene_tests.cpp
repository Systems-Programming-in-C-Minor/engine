#include "../include/scene.hpp"
#include "../../mocks/mock_gameobject.hpp"
#include "../../mocks/mock_renderer.hpp"

#include "gtest/gtest.h"

#define mock_game_object std::make_shared<MockGameObject>("TestGameObject", "TestTag")

TEST(SceneTest, Tick_OneGameObject) {
    auto game_object1 = mock_game_object;
    auto scene = Scene();

    scene.gameobjects.push_back(game_object1);
    
    EXPECT_CALL(*game_object1, tick()).Times(1);
    
    scene.tick();
}

TEST(SceneTest, Tick_ThreeGameObjects) {
    auto game_object1 = mock_game_object;
    auto game_object2 = mock_game_object;
    auto game_object3 = mock_game_object;
    auto scene = Scene();

    scene.gameobjects.push_back(game_object1);
    scene.gameobjects.push_back(game_object2);
    scene.gameobjects.push_back(game_object3);

    EXPECT_CALL(*game_object1, tick()).Times(2);
    EXPECT_CALL(*game_object2, tick()).Times(2);
    EXPECT_CALL(*game_object3, tick()).Times(2);

    scene.tick();
    scene.tick();
}

TEST(SceneTest, Render_OneGameObject) {
    auto game_object1 = mock_game_object;
    auto scene = Scene();
    auto renderer = MockRenderer();

    scene.gameobjects.push_back(game_object1);

    EXPECT_CALL(*game_object1, render()).Times(1);

    scene.render();
}

TEST(SceneTest, Render_ThreeGameObjects) {
    auto game_object1 = mock_game_object;
    auto game_object2 = mock_game_object;
    auto game_object3 = mock_game_object;
    auto scene = Scene();
    auto renderer = MockRenderer();

    scene.gameobjects.push_back(game_object1);
    scene.gameobjects.push_back(game_object2);
    scene.gameobjects.push_back(game_object3);

    EXPECT_CALL(*game_object1, render()).Times(2);
    EXPECT_CALL(*game_object2, render()).Times(2);
    EXPECT_CALL(*game_object3, render()).Times(2);

    scene.render();
    scene.render();
}
