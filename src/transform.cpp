#include "transform.hpp"


float Transform::get_angle() const
{
	return _angle;
}

void Transform::set_angle(float angle)
{
	_angle = angle;
}

float Transform::get_scale() const
{
	return _scale;
}

void Transform::set_scale(float scale)
{
	_scale = scale;
}

Vector2d Transform::get_position() const
{
	return _position;
}

void Transform::set_position(const Vector2d& position)
{
	_position = position;
}

Transform::Transform(const Vector2d& position, float angle, float scale):
	_position(position),
	_angle(angle),
	_scale(scale) {}