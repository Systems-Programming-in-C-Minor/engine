#include <gtest/gtest.h>
#include "vector2d.hpp"

TEST(Vector2dTest, EqualsTestOverload)
{
	Vector2d vec1(0.5, 0.2);
	Vector2d vec2(0.5, 0.2);
	EXPECT_EQ(vec1, vec2);

	Vector2d vec3(0.5, 0.5);;
	EXPECT_NE(vec1, vec3);
}

TEST(Vector2dTest, AddTestOverload)
{
	Vector2d vec1(0.2, 0.3);
	Vector2d vec2(0.3, 0.2);

	Vector2d vec3 = vec1 + vec2;
	Vector2d vec4(0.5, 0.5);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, SubtractTestOverload)
{
	Vector2d vec1(0.3, 0.3);
	Vector2d vec2(0.5, 0.1);

	Vector2d vec3 = vec1 - vec2;
	Vector2d vec4(-0.2, 0.2);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, MultiplyTestOverload)
{
	Vector2d vec1(0.3, 0.3);
	Vector2d vec2(-0.3, 0.2);

	Vector2d vec3 = vec1 * vec2;
	Vector2d vec4(-0.09, 0.06);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, MultiplyFloatTestOverload)
{
    Vector2d vec1(0.3, 0.3);
    float flo = 0.3f;

    Vector2d vec3 = vec1 * flo;
    Vector2d vec4(0.09, 0.09);

    EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, DivideTestOverload)
{
	Vector2d vec1(1.0, 1.0);
	Vector2d vec2(-0.5, 0.2);

	Vector2d vec3 = vec1 / vec2;
	Vector2d vec4(-2.0, 5.0);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, DivideByZeroTestOverload)
{
	Vector2d vec1(1.0, 1.0);
	Vector2d vec2(0.0, 0.2);
	Vector2d vec3(0.2, 0.0);

	Vector2d vec4 = vec1 / vec2;
	Vector2d vec5 = vec1 / vec3;

	EXPECT_EQ(vec1, vec4);
	EXPECT_EQ(vec1, vec5);
}

TEST(Vector2dTest, EqualsTestFunc)
{
	Vector2d vec1(0.5, 0.2);
	Vector2d vec2(0.5, 0.2);
	EXPECT_TRUE(vec1.equals(vec2));

	Vector2d vec3(0.5, 0.5);;
	EXPECT_FALSE(vec1.equals(vec3));
}

TEST(Vector2dTest, AddTestFunc)
{
	Vector2d vec1(0.2, 0.3);
	Vector2d vec2(0.3, 0.2);

	Vector2d vec3 = vec1.add(vec2);
	Vector2d vec4(0.5, 0.5);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, SubtractTestFunc)
{
	Vector2d vec1(0.3, 0.3);
	Vector2d vec2(0.5, 0.1);

	Vector2d vec3 = vec1.subtract(vec2);
	Vector2d vec4(-0.2, 0.2);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, MultiplyTestFunc)
{
	Vector2d vec1(0.3, 0.3);
	Vector2d vec2(-0.3, 0.2);

	Vector2d vec3 = vec1.multiply(vec2);
	Vector2d vec4(-0.09, 0.06);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, MultiplyFloatTestFunc)
{
    Vector2d vec1(0.3, 0.3);
    float flo = 0.3f;

    Vector2d vec3 = vec1.multiply(flo);
    Vector2d vec4(0.09, 0.09);

    EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, DivideTestFunc)
{
	Vector2d vec1(1.0, 1.0);
	Vector2d vec2(-0.5, 0.2);

	Vector2d vec3 = vec1.divide(vec2);
	Vector2d vec4(-2.0, 5.0);

	EXPECT_TRUE(vec3.almost_equals(vec4, 0.0001));
}

TEST(Vector2dTest, DivideByZeroTestFunc)
{
	Vector2d vec1(1.0, 1.0);
	Vector2d vec2(0.0, 0.2);
	Vector2d vec3(0.2, 0.0);

	Vector2d vec4 = vec1.divide(vec2);
	Vector2d vec5 = vec1.divide(vec3);

	EXPECT_EQ(vec1, vec4);
	EXPECT_EQ(vec1, vec5);
}