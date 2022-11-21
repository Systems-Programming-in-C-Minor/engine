#include <gtest/gtest.h>
#include "components/colliders/spritecollider.hpp"

auto test_spritecollider = new SpriteCollider();

TEST(SpriteColliderTest, GetAndSetPath){
    std::string test_value = "test";

    test_spritecollider->set_path(test_value);

    EXPECT_EQ("test", test_spritecollider->get_path());
}

TEST(SpriteColliderTest, ConstructorTest){
    std::string test_value = "test2";
    auto test_spritecollider2 = new SpriteCollider(test_value);

    EXPECT_EQ("test2", test_spritecollider2->get_path());
}