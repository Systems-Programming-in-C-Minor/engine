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

Vector2d::Vector2d(const double x, const double y)
    : x(x),	y(y) {}


std::ostream& operator<<(std::ostream& stream, const Vector2d& vector)
{
    stream << vector.x << ", " << vector.y;
    return stream;
}