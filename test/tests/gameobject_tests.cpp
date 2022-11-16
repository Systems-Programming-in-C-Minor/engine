#include <gtest/gtest.h>
#include "gameobject.hpp"
#include "../mocks/mock_renderable_component.hpp"
#include "../mocks/mock_tickable_component.hpp"
#include "../mocks/mock_tickable_renderable_component.hpp"
#include "../mocks/mock_renderer.hpp"

#define test_game_object GameObject("TestGameObject", "TestTag")
#define test_game_object_ptr std::make_shared<GameObject>("TestGameObject", "TestTag")
#define contains(list, item) std::find(list.begin(), list.end(),item) != list.end()

class Test1Component : public Component {
};

class Test2Component : public Component {
};

class Test3Component : public Component {
};

TEST(GameObjectTest, GetSetActive) {
    auto game_object = test_game_object;
    game_object.set_active(true);
    EXPECT_TRUE(game_object.is_active());
    game_object.set_active(false);
    EXPECT_FALSE(game_object.is_active());
}

TEST(GameObjectTest, AddGetComponent) {
    auto game_object = test_game_object;

    const auto test1_component = std::make_shared<Test1Component>();
    const auto test2_component = std::make_shared<Test2Component>();

    game_object.add_component(test1_component);
    game_object.add_component(test2_component);

    EXPECT_EQ(game_object.get_component<Test1Component>(), test1_component);
    EXPECT_EQ(game_object.get_component<Test2Component>(), test2_component);
    EXPECT_EQ(game_object.get_component<Test3Component>(), nullptr);
}

TEST(GameObjectTest, RemoveComponent) {
    auto game_object = test_game_object;

    const auto test1_component = std::make_shared<Test1Component>();
    const auto test2_component = std::make_shared<Test2Component>();

    game_object.add_component(test1_component);
    game_object.add_component(test2_component);

    EXPECT_EQ(game_object.get_component<Test1Component>(), test1_component);
    EXPECT_EQ(game_object.get_component<Test2Component>(), test2_component);

    game_object.remove_component(test1_component);

    EXPECT_EQ(game_object.get_component<Test1Component>(), nullptr);
    EXPECT_EQ(game_object.get_component<Test2Component>(), test2_component);
}

TEST(GameObjectTest, AddGetComponents) {
    auto game_object = test_game_object;

    const auto test1_component1 = std::make_shared<Test1Component>();
    const auto test1_component2 = std::make_shared<Test1Component>();
    const auto test2_component1 = std::make_shared<Test2Component>();
    const auto test2_component2 = std::make_shared<Test2Component>();

    game_object.add_component(test1_component1);
    game_object.add_component(test2_component1);
    game_object.add_component(test1_component2);
    game_object.add_component(test2_component2);

    const auto test1_components = game_object.get_components<Test1Component>();

    EXPECT_EQ(test1_components.size(), 2);
    EXPECT_TRUE(contains(test1_components, test1_component1));
    EXPECT_TRUE(contains(test1_components, test1_component2));

    const auto test2_components = game_object.get_components<Test2Component>();

    EXPECT_EQ(test2_components.size(), 2);
    EXPECT_TRUE(contains(test2_components, test2_component1));
    EXPECT_TRUE(contains(test2_components, test2_component2));

    const auto test3_components = game_object.get_components<Test3Component>();

    EXPECT_EQ(test3_components.size(), 0);
}

TEST(GameObjectTest, AddGetRemoveChildren) {
    auto game_object = test_game_object;
    const auto child1 = test_game_object_ptr;
    const auto child2 = test_game_object_ptr;

    EXPECT_EQ(game_object.get_children().size(), 0);

    game_object.add_child(child1);
    game_object.add_child(child2);

    EXPECT_EQ(game_object.get_children().size(), 2);
    EXPECT_TRUE(contains(game_object.get_children(), child1));
    EXPECT_TRUE(contains(game_object.get_children(), child2));

    game_object.remove_child(child1);

    EXPECT_EQ(game_object.get_children().size(), 1);
    EXPECT_TRUE(contains(game_object.get_children(), child2));
}

TEST(GameObjectTest, GetChildComponent) {
    auto game_object = test_game_object;
    const auto child = test_game_object_ptr;
    const auto child_child = test_game_object_ptr;

    const auto test1_component = std::make_shared<Test1Component>();
    const auto test2_component = std::make_shared<Test2Component>();
    const auto test3_component = std::make_shared<Test3Component>();

    game_object.add_child(child);
    child->add_child(child_child);

    game_object.add_component(test1_component);
    child->add_component(test2_component);
    child_child->add_component(test3_component);

    EXPECT_EQ(game_object.get_component_in_children<Test1Component>(), test1_component);
    EXPECT_EQ(game_object.get_component_in_children<Test2Component>(), test2_component);
    EXPECT_EQ(game_object.get_component_in_children<Test3Component>(), test3_component);
}

TEST(GameObjectTest, GetChildComponents) {
    auto game_object = test_game_object;
    const auto child = test_game_object_ptr;
    const auto child_child = test_game_object_ptr;

    const auto test1_component1 = std::make_shared<Test1Component>();
    const auto test1_component2 = std::make_shared<Test1Component>();
    const auto test2_component1 = std::make_shared<Test2Component>();
    const auto test2_component2 = std::make_shared<Test2Component>();
    const auto test3_component1 = std::make_shared<Test3Component>();

    game_object.add_component(test1_component1);
    game_object.add_component(test2_component1);
    child->add_component(test1_component2);
    child->add_component(test2_component2);
    child_child->add_component(test3_component1);

    game_object.add_child(child);
    child->add_child(child_child);

    const auto test1_components = game_object.get_components_in_children<Test1Component>();

    EXPECT_EQ(test1_components.size(), 2);
    EXPECT_TRUE(contains(test1_components, test1_component1));
    EXPECT_TRUE(contains(test1_components, test1_component2));\

    const auto test2_components = game_object.get_components_in_children<Test2Component>();

    EXPECT_EQ(test2_components.size(), 2);
    EXPECT_TRUE(contains(test2_components, test2_component1));
    EXPECT_TRUE(contains(test2_components, test2_component2));

    const auto test3_components = game_object.get_components_in_children<Test3Component>();

    EXPECT_EQ(test3_components.size(), 1);
}

TEST(GameObjectTest, Render) {
    auto game_object = test_game_object;
    const auto child = test_game_object_ptr;
    const auto child_child = test_game_object_ptr;

    auto renderer = MockRenderer();

    const auto test_component1 = std::make_shared<Test1Component>();
    const auto render_component1 = std::make_shared<MockRenderableComponent>();
    const auto render_component2 = std::make_shared<MockRenderableComponent>();
    const auto render_component3 = std::make_shared<MockRenderableComponent>();
    const auto tick_render_component = std::make_shared<MockTickableRenderableComponent>();

    EXPECT_CALL(*render_component1, render(testing::_, testing::_))
            .Times(1);

    EXPECT_CALL(*render_component2, render(testing::_, testing::_))
            .Times(1);

    EXPECT_CALL(*render_component3, render(testing::_, testing::_))
            .Times(1);

    EXPECT_CALL(*tick_render_component, render(testing::_, testing::_))
            .Times(1);

    game_object.add_component(test_component1);
    game_object.add_component(render_component1);
    game_object.add_component(tick_render_component);
    child->add_component(render_component2);
    child_child->add_component(render_component3);

    game_object.add_child(child);
    child->add_child(child_child);

    game_object.render(renderer);
}

TEST(GameObjectTest, Tick) {
    auto game_object = test_game_object;
    const auto child = test_game_object_ptr;
    const auto child_child = test_game_object_ptr;

    const auto test_component1 = std::make_shared<Test1Component>();
    const auto tick_component1 = std::make_shared<MockTickableComponent>();
    const auto tick_component2 = std::make_shared<MockTickableComponent>();
    const auto tick_component3 = std::make_shared<MockTickableComponent>();
    const auto tick_render_component = std::make_shared<MockTickableRenderableComponent>();

    EXPECT_CALL(*tick_component1, tick(game_object))
            .Times(1);

    EXPECT_CALL(*tick_component2, tick(game_object))
            .Times(1);

    EXPECT_CALL(*tick_component3, tick(game_object))
            .Times(1);

    EXPECT_CALL(*tick_render_component, tick(game_object))
            .Times(1);

    game_object.add_component(test_component1);
    game_object.add_component(tick_component1);
    game_object.add_component(tick_render_component);
    child->add_component(tick_component2);
    child_child->add_component(tick_component3);

    game_object.add_child(child);
    child->add_child(child_child);

    game_object.tick();
}

TEST(GameObjectTest, ActiveInWorld) {
    auto game_object = test_game_object;
    const auto child = test_game_object_ptr;
    const auto child_child = test_game_object_ptr;

    game_object.add_child(child);
    child->add_child(child_child);

    game_object.set_active(false);
    child->set_active(true);
    child_child->set_active(true);

    EXPECT_FALSE(game_object.is_active_in_world());
    EXPECT_FALSE(child->is_active_in_world());
    EXPECT_FALSE(child_child->is_active_in_world());

    game_object.set_active(true);

    EXPECT_TRUE(game_object.is_active_in_world());
    EXPECT_TRUE(child->is_active_in_world());
    EXPECT_TRUE(child_child->is_active_in_world());

    child->set_active(false);

    EXPECT_TRUE(game_object.is_active_in_world());
    EXPECT_FALSE(child->is_active_in_world());
    EXPECT_FALSE(child_child->is_active_in_world());
}

TEST(GameObjectTest, Equals) {
    auto game_object1 = test_game_object;
    auto game_object2 = test_game_object;
    auto game_object3 = GameObject("abc", "123");

    ASSERT_EQ(game_object1, game_object1);
    ASSERT_NE(game_object1, game_object2);
    ASSERT_NE(game_object1, game_object3);
}
