#include "box2d/b2_math.h"
#include "utils/trigonometry.hpp"
#include <cmath>
#include "vector2d.hpp"


Vector2d Vector2d::add(const Vector2d& other) const
{
    return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator+(const Vector2d& other) const
{
    return add(other);
}

Vector2d Vector2d::subtract(const Vector2d& other) const
{
    return Vector2d(x - other.x, y - other.y);
}


Vector2d Vector2d::operator-(const Vector2d& other) const
{
    return subtract(other);
}

Vector2d Vector2d::multiply(const Vector2d& other) const
{
    return Vector2d(x * other.x, y * other.y);
}

Vector2d Vector2d::operator*(const Vector2d& other) const
{
    return multiply(other);
}

Vector2d Vector2d::multiply(const float other) const
{
    return Vector2d(x * other, y * other);
}

Vector2d Vector2d::operator*(const float other) const
{
    return multiply(other);
}

Vector2d Vector2d::divide(const float other) const
{
    return Vector2d(x / other, y / other);
}

Vector2d Vector2d::operator/(const float other) const
{
    return divide(other);
}

Vector2d Vector2d::divide(const Vector2d& other) const
{
    if (other.x == 0.0 || other.y == 0.0)
        return *this;
    return Vector2d(x / other.x, y / other.y);
}

Vector2d Vector2d::operator/(const Vector2d& other) const
{
    return divide(other);
}

bool Vector2d::equals(const Vector2d& other) const
{
    return x == other.x && y == other.y;
}

bool Vector2d::operator==(const Vector2d& other) const
{
    return equals(other);
}

bool Vector2d::almost_equals(const Vector2d& other, const double epsilon) const
{
    return (std::abs(x - other.x) < epsilon && std::abs(y - other.y) < epsilon);
}

float Vector2d::length() const {
    return b2Vec2(x, y).Length();
}

float Vector2d::normalized_length() const {
    return b2Vec2(x, y).Normalize();
}

float Vector2d::normalize() {
    auto vec = b2Vec2(x,y);
    const auto length = vec.Normalize();
    x = vec.x;
    y = vec.y;
    return length;
}

float Vector2d::dot(const Vector2d &a, const Vector2d &b) {
    return b2Dot(static_cast<b2Vec2>(a),static_cast<b2Vec2>(b));
}

float Vector2d::cross(const Vector2d &a, const Vector2d &b) {
    return b2Cross(static_cast<b2Vec2>(a),static_cast<b2Vec2>(b));
}

float Vector2d::angle(const Vector2d &from, const Vector2d &to) {
    auto a = static_cast<b2Vec2>(from);
    auto b = static_cast<b2Vec2>(to);

    float denominator = sqrt(a.LengthSquared() * b.LengthSquared());
    float k_epsilon_normal_sqrt = 1e-15f;
    if (denominator < k_epsilon_normal_sqrt)
        return 0.f;

    float dot = b2Clamp(b2Dot(a,b) / denominator, -1.f, 1.f);

    return radians_to_degrees(acos(dot));
}

float Vector2d::signed_angle(const Vector2d &from, const Vector2d &to, const Vector2d &axis) {
    auto a = static_cast<b2Vec2>(from);
    auto b = static_cast<b2Vec2>(to);

    return atan2(a.x * b.y - a.y * b.x, a.x * b.x + a.y * b.y);
}

float Vector2d::distance(const Vector2d &a, const Vector2d &b) {
    auto c = static_cast<b2Vec2>(a);
    auto d = static_cast<b2Vec2>(b);

    return b2Distance(c,d);
}

Vector2d::Vector2d(const float x, const float y)
    : x(x),	y(y) {}

Vector2d::Vector2d(const b2Vec2& b2vec)
	: x(b2vec.x), y(b2vec.y)
{}

Vector2d::operator b2Vec2() const
{
    return b2Vec2{ x, y };
}

std::ostream& operator<<(std::ostream& stream, const Vector2d& vector)
{
    stream << vector.x << ", " << vector.y;
    return stream;
}
