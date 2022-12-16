#include <gtest/gtest.h>
#include <list>
#include "networking/networking_test.hpp"

TEST(NetworkingTest, Client) {
    auto x = NetworkingTest();
    x.client();
}

TEST(NetworkingTest, Host) {
    auto x = NetworkingTest();
    x.host();
}
