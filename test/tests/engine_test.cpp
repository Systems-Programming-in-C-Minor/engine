#include <gtest/gtest.h>
#include "engine.hpp"
#include "../mocks/mock_scene.hpp"
#include <chrono>

#define mock_scene std::make_shared<MockScene>()
#define test_engine Engine()

using testing::AllOf;
using testing::Ge;
using testing::Le;

TEST(EngineTest, LoadScene) {
    auto engine = test_engine;
    auto scene = mock_scene;

    engine.load_scene(scene);

    EXPECT_EQ(&engine.get_active_scene(), &*scene);
}

TEST(EngineTest, TickRenderLoopAndStop) {
    auto engine = test_engine;
    auto scene = mock_scene;

    engine.load_scene(scene);

    unsigned int counter = 0;

    EXPECT_CALL(*scene, tick())
            .Times(3)
            .WillRepeatedly([&engine, &counter] {
                if (++counter >= 3) {
                    engine.stop();
                }
            });

    EXPECT_CALL(*scene, render(testing::_))
            .Times(3);

    engine.start();
}

TEST(EngineTest, Fps) {
    auto engine = test_engine;
    auto scene = mock_scene;

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

    EXPECT_CALL(*scene, render(testing::_))
            .Times(3);

    engine.start();

    // Allow for a small difference in case the computer is slow.
    EXPECT_THAT(engine.get_fps(), AllOf(Ge(9), Le(11)));
}
