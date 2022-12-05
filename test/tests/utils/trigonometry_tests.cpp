#include <gtest/gtest.h>
#include "utils/trigonometry.hpp"

TEST(TrigonometryTest, RadiansToDegreesTest)
{
	constexpr double deg1 = 57.295779513082321;
	constexpr double deg2 = 200.535228295788123;

	EXPECT_DOUBLE_EQ(deg1, radians_to_degrees(1.0));
	EXPECT_DOUBLE_EQ(deg2, radians_to_degrees(3.5));
}

TEST(TrigonometryTest, RadiansToDegreesTestNegative)
{
	constexpr double deg1 = -57.295779513082321;
	constexpr double deg2 = -200.535228295788123;

	EXPECT_DOUBLE_EQ(deg1, radians_to_degrees(-1.0));
	EXPECT_DOUBLE_EQ(deg2, radians_to_degrees(-3.5));
}

TEST(TrigonometryTest, DegreesToRadiansTest)
{
	constexpr double deg1 = 6.9813170079773183;
	constexpr double deg2 = 0.1745329251994330;

	EXPECT_DOUBLE_EQ(deg1, degrees_to_radians(400.0));
	EXPECT_DOUBLE_EQ(deg2, degrees_to_radians(10.0));
}

TEST(TrigonometryTest, DegreesToRadiansTestNegative)
{
	constexpr double deg1 = -6.9813170079773183;
	constexpr double deg2 = -0.1745329251994330;

	EXPECT_DOUBLE_EQ(deg1, degrees_to_radians(-400.0));
	EXPECT_DOUBLE_EQ(deg2, degrees_to_radians(-10.0));
}