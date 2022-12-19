#include "box2d/b2_math.h"

#include "vector2d.hpp"

#include "SDL2pp/Point.hh"


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

float Vector2d::normalize() const {
    return b2Vec2(x, y).Normalize();
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

Vector2d::Vector2d(const SDL2pp::Point& point) :
	x(static_cast<float>(point.GetX())),
	y(static_cast<float>(point.GetY()))
{}

Vector2d::operator SDL2pp::Point() const
{
    return {
        static_cast<int>(this->x),
        static_cast<int>(this->y)
    };
}

std::ostream& operator<<(std::ostream& stream, const Vector2d& vector)
{
    stream << vector.x << ", " << vector.y;
    return stream;
}
