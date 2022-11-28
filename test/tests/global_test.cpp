#include <gtest/gtest.h>
#include "global.hpp"
#include "../mocks/mock_engine.hpp"
#include "../mocks/mock_scene.hpp"
#include "../mocks/mock_properties.hpp"

using testing::Return;
using testing::ReturnRef;
using testing::Const;

TEST(GlobalTest, GetSetEngine) {
    auto global = Global::get_instance();
    auto engine = std::make_unique<MockEngine>();

    const auto ref = &*engine;

    global->set_engine(std::move(engine));
    EXPECT_EQ(&global->get_engine(), ref);

    global->set_engine(nullptr);
}

TEST(GlobalTest, GetSetProperties) {
    auto global = Global::get_instance();
    auto properties = std::make_unique<MockProperties>();

    const auto ref = &*properties;

    global->set_properties(std::move(properties));
    EXPECT_EQ(&global->get_properties(), ref);

    global->set_properties(nullptr);
}

TEST(GlobalTest, GetActiveScene) {
    auto global = Global::get_instance();
    auto mock_engine = std::make_unique<MockEngine>();
    auto mock_scene = MockScene();

    EXPECT_CALL(*mock_engine, get_active_scene())
            .Times(1)
            .WillOnce(ReturnRef(mock_scene));

    global->set_engine(std::move(mock_engine));
    EXPECT_EQ(&global->get_engine().get_active_scene(), &mock_scene);

    global->set_engine(nullptr);
}
