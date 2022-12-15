#include <gtest/gtest.h>
#include "engine.hpp"
#include "../mocks/mock_scene.hpp"
#include "../mocks/mock_renderer.hpp"
#include "../mocks/mock_audio_engine.hpp"
#include <chrono>
#include <memory>

#define mock_scene std::make_shared<MockScene>()
#define test_engine(renderer, audio_engine) Engine(renderer, audio_engine)

using testing::AllOf;
using testing::Ge;
using testing::Le;

TEST(EngineTest, LoadScene) {
    auto renderer = std::make_shared<MockRenderer>();
    auto audio_engine = std::make_shared<MockAudioEngine>();
    auto engine = test_engine(renderer, audio_engine);
    auto scene = mock_scene;

    engine.load_scene(scene);

    EXPECT_EQ(&engine.get_active_scene(), &*scene);
}
