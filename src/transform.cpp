#include "transform.hpp"


double Transform::get_angle()
{
	return _angle;
}

void Transform::set_angle(double angle)
{
	_angle = angle;
}

double Transform::get_scale()
{
	return _scale;
}

void Transform::set_scale(double scale)
{
	_scale = scale;
}

Vector2d Transform::get_position()
{
	return _position;
}

void Transform::set_position(Vector2d & position)
{
	_position = position;
}

Transform::Transform(const Vector2d& position, double angle, double scale):
	_position(position),
	_angle(angle),
	_scale(scale) {}