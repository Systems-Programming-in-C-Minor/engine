#include <gtest/gtest.h>
#include "GameObject.hpp"

#define testGameObject GameObject("TestGameObject", "TestTag")
#define testGameObjectPtr std::make_shared<GameObject>("TestGameObject", "TestTag")
#define contains(list, item) std::find(list.begin(), list.end(),item) != list.end()

class Test1Component : public Component {
};

class Test2Component : public Component {
};

class Test3Component : public Component {
};

TEST(GameObjectTest, GetSetActive) {
    auto gameObject = testGameObject;
    gameObject.setActive(true);
    EXPECT_TRUE(gameObject.isActive());
    gameObject.setActive(false);
    EXPECT_FALSE(gameObject.isActive());
}

TEST(GameObjectTest, AddGetComponent) {
    auto gameObject = testGameObject;

    const auto test1Component = std::make_shared<Test1Component>();
    const auto test2Component = std::make_shared<Test2Component>();

    gameObject.addComponent(test1Component);
    gameObject.addComponent(test2Component);

    EXPECT_EQ(gameObject.getComponent<Test1Component>(), test1Component);
    EXPECT_EQ(gameObject.getComponent<Test2Component>(), test2Component);
    EXPECT_EQ(gameObject.getComponent<Test3Component>(), nullptr);
}

TEST(GameObjectTest, AddGetComponents) {
    auto gameObject = testGameObject;

    const auto test1Component1 = std::make_shared<Test1Component>();
    const auto test1Component2 = std::make_shared<Test1Component>();
    const auto test2Component1 = std::make_shared<Test2Component>();
    const auto test2Component2 = std::make_shared<Test2Component>();

    gameObject.addComponent(test1Component1);
    gameObject.addComponent(test2Component1);
    gameObject.addComponent(test1Component2);
    gameObject.addComponent(test2Component2);

    const auto test1Components = gameObject.getComponents<Test1Component>();

    EXPECT_EQ(test1Components.size(), 2);
    EXPECT_TRUE(contains(test1Components, test1Component1));
    EXPECT_TRUE(contains(test1Components, test1Component2));

    const auto test2Components = gameObject.getComponents<Test2Component>();

    EXPECT_EQ(test2Components.size(), 2);
    EXPECT_TRUE(contains(test2Components, test2Component1));
    EXPECT_TRUE(contains(test2Components, test2Component2));

    const auto test3Components = gameObject.getComponents<Test3Component>();

    EXPECT_EQ(test3Components.size(), 0);
}

TEST(GameObjectTest, AddGetRemoveChildren) {
    auto gameObject = testGameObject;
    const auto child1 = testGameObjectPtr;
    const auto child2 = testGameObjectPtr;

    EXPECT_EQ(gameObject.getChildren().size(), 0);

    gameObject.addChild(child1);
    gameObject.addChild(child2);

    EXPECT_EQ(gameObject.getChildren().size(), 2);
    EXPECT_TRUE(contains(gameObject.getChildren(), child1));
    EXPECT_TRUE(contains(gameObject.getChildren(), child2));

    gameObject.removeChild(child1);

    EXPECT_EQ(gameObject.getChildren().size(), 1);
    EXPECT_TRUE(contains(gameObject.getChildren(), child2));
}

TEST(GameObjectTest, GetChildComponent) {
    auto gameObject = testGameObject;
    const auto child = testGameObjectPtr;
    const auto childChild = testGameObjectPtr;

    const auto test1Component = std::make_shared<Test1Component>();
    const auto test2Component = std::make_shared<Test2Component>();
    const auto test3Component = std::make_shared<Test3Component>();

    gameObject.addChild(child);
    child->addChild(childChild);

    gameObject.addComponent(test1Component);
    child->addComponent(test2Component);
    childChild->addComponent(test3Component);

    EXPECT_EQ(gameObject.getComponentInChildren<Test1Component>(), test1Component);
    EXPECT_EQ(gameObject.getComponentInChildren<Test2Component>(), test2Component);
    EXPECT_EQ(gameObject.getComponentInChildren<Test3Component>(), test3Component);
}

TEST(GameObjectTest, GetChildComponents) {
    auto gameObject = testGameObject;
    const auto child = testGameObjectPtr;
    const auto childChild = testGameObjectPtr;

    const auto test1Component1 = std::make_shared<Test1Component>();
    const auto test1Component2 = std::make_shared<Test1Component>();
    const auto test2Component1 = std::make_shared<Test2Component>();
    const auto test2Component2 = std::make_shared<Test2Component>();
    const auto test3Component1 = std::make_shared<Test3Component>();

    gameObject.addComponent(test1Component1);
    gameObject.addComponent(test2Component1);
    child->addComponent(test1Component2);
    child->addComponent(test2Component2);
    childChild->addComponent(test3Component1);

    gameObject.addChild(child);
    child->addChild(childChild);

    const auto test1Components = gameObject.getComponentsInChildren<Test1Component>();

    EXPECT_EQ(test1Components.size(), 2);
    EXPECT_TRUE(contains(test1Components, test1Component1));
    EXPECT_TRUE(contains(test1Components, test1Component2));\

    const auto test2Components = gameObject.getComponentsInChildren<Test2Component>();

    EXPECT_EQ(test2Components.size(), 2);
    EXPECT_TRUE(contains(test2Components, test2Component1));
    EXPECT_TRUE(contains(test2Components, test2Component2));

    const auto test3Components = gameObject.getComponentsInChildren<Test3Component>();

    EXPECT_EQ(test3Components.size(), 1);
}

TEST(GameObjectTest, ActiveInWorld) {
    auto gameObject = testGameObject;
    const auto child = testGameObjectPtr;
    const auto childChild = testGameObjectPtr;

    gameObject.addChild(child);
    child->addChild(childChild);

    gameObject.setActive(false);
    child->setActive(true);
    childChild->setActive(true);

    EXPECT_FALSE(gameObject.isActiveInWorld());
    EXPECT_FALSE(child->isActiveInWorld());
    EXPECT_FALSE(childChild->isActiveInWorld());

    gameObject.setActive(true);

    EXPECT_TRUE(gameObject.isActiveInWorld());
    EXPECT_TRUE(child->isActiveInWorld());
    EXPECT_TRUE(childChild->isActiveInWorld());

    child->setActive(false);

    EXPECT_TRUE(gameObject.isActiveInWorld());
    EXPECT_FALSE(child->isActiveInWorld());
    EXPECT_FALSE(childChild->isActiveInWorld());
}

TEST(GameObjectTest, Equals) {
    auto gameObject1 = testGameObject;
    auto gameObject2 = testGameObject;
    auto gameObject3 = GameObject("abc", "123");

    ASSERT_EQ(gameObject1, gameObject1);
    ASSERT_NE(gameObject1, gameObject2);
    ASSERT_NE(gameObject1, gameObject3);
}
