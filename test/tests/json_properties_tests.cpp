#include <gtest/gtest.h>
#include <filesystem>
#include "storage/json_properties.hpp"

const auto test_filename = "test.json";

TEST(JsonPropertiesTest, CreateFileWhenNoneExists) {
    if (std::filesystem::exists(test_filename)) {
        std::filesystem::remove(test_filename);
    }

    auto properties = JsonProperties(test_filename);

    ASSERT_TRUE(std::filesystem::exists(test_filename));

    auto file = std::ifstream(test_filename);
    auto buffer = std::stringstream();
    buffer << file.rdbuf();

    EXPECT_EQ(buffer.str(), "{}\n");
}

TEST(JsonPropertiesTest, ReadAndWritePropertie) {
    if (std::filesystem::exists(test_filename)) {
        std::filesystem::remove(test_filename);
    }

    auto properties = JsonProperties(test_filename);

    EXPECT_EQ(properties.get_property("testing"), std::nullopt);

    properties.set_property("testing", "abc");

    EXPECT_EQ(properties.get_property("testing"), "abc");
}

TEST(JsonPropertiesTest, IsPersistant) {
    if (std::filesystem::exists(test_filename)) {
        std::filesystem::remove(test_filename);
    }

    auto properties1 = JsonProperties(test_filename);
    properties1.set_property("testing", "def");


    auto properties2 = JsonProperties(test_filename);
    EXPECT_EQ(properties2.get_property("testing"), "def");
}
