#include <gtest/gtest.h>
#include "vector2d.hpp"

TEST(Vector2dTest, EqualsTest)
{
	Vector2d vec1(0.5, 0.2);
	Vector2d vec2(0.5, 0.2);
	EXPECT_EQ(vec1, vec2);

	Vector2d vec3(0.5, 0.5);;
	EXPECT_NE(vec1, vec3);
}

TEST(Vector2dTest, AddTest)
{
	Vector2d vec1(0.2, 0.3);
	Vector2d vec2(0.3, 0.2);

	Vector2d vec3 = vec1 + vec2;
	Vector2d vec4(0.5, 0.5);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, SubtractTest)
{
	Vector2d vec1(0.3, 0.3);
	Vector2d vec2(0.5, 0.1);

	Vector2d vec3 = vec1 - vec2;
	Vector2d vec4(-0.2, 0.2);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, MultiplyTest)
{
	Vector2d vec1(0.3, 0.3);
	Vector2d vec2(-0.3, 0.2);

	Vector2d vec3 = vec1 * vec2;
	Vector2d vec4(-0.09, 0.06);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, DivideTest)
{
	Vector2d vec1(1.0, 1.0);
	Vector2d vec2(-0.5, 0.2);

	Vector2d vec3 = vec1 / vec2;
	Vector2d vec4(-2.0, 5.0);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, DivideByZeroTest)
{
	Vector2d vec1(1.0, 1.0);
	Vector2d vec2(0.0, 0.2);
	Vector2d vec3(0.2, 0.0);

	Vector2d vec4 = vec1 / vec2;
	Vector2d vec5 = vec1 / vec3;

	EXPECT_EQ(vec1, vec4);
	EXPECT_EQ(vec1, vec5);
}