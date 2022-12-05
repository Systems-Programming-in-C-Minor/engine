#include <gtest/gtest.h>
#include "engine.hpp"
#include "../mocks/mock_scene.hpp"
#include "../mocks/mock_renderer.hpp"
#include <chrono>
#include <memory>

#define mock_scene std::make_shared<MockScene>()
#define test_engine(renderer) Engine(renderer)

using testing::AllOf;
using testing::Ge;
using testing::Le;

TEST(EngineTest, LoadScene) {
    auto renderer = std::make_shared<MockRenderer>();
    auto engine = test_engine(renderer);
    auto scene = mock_scene;

    engine.load_scene(scene);

    EXPECT_EQ(&engine.get_active_scene(), &*scene);
}

TEST(EngineTest, TickRenderLoopAndStop) {
    auto renderer = std::make_shared<MockRenderer>();
    auto engine = test_engine(renderer);
    auto scene = mock_scene;

    EXPECT_CALL(*renderer, clear(testing::_))
            .Times(3);

    EXPECT_CALL(*renderer, push_to_screen())
            .Times(3);

    unsigned int counter = 0;

    EXPECT_CALL(*scene, tick())
            .Times(3)
            .WillRepeatedly([&engine, &counter] {
                if (++counter >= 3) {
                    engine.stop();
                }
            });

    EXPECT_CALL(*scene, render())
            .Times(3);

    engine.load_scene(scene);

    engine.start();
}

TEST(EngineTest, Fps) {
    auto renderer = std::make_shared<MockRenderer>();
    auto engine = test_engine(renderer);
    auto scene = mock_scene;

    EXPECT_CALL(*renderer, clear(testing::_))
            .Times(3);

    EXPECT_CALL(*renderer, push_to_screen())
            .Times(3);

    engine.load_scene(scene);

    unsigned int counter = 0;

    EXPECT_CALL(*scene, tick())
            .Times(3)
            .WillRepeatedly([&engine, &counter] {
                if (++counter >= 3) {
                    engine.stop();
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            });

    EXPECT_CALL(*scene, render())
            .Times(3);

    engine.start();

    // Allow for a small difference in case the computer is slow.
    EXPECT_THAT(engine.get_fps(), AllOf(Ge(9), Le(11)));
}
