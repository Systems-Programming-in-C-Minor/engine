#include "transform.hpp"



double Transform::get_angle()
{
	return angle;
}

void Transform::set_angle(double angle)
{
	this->angle = angle;
}

double Transform::get_scale()
{
	return scale;
}

void Transform::set_scale(double scale)
{
	this->scale = scale;
}

Transform::Transform(const Vector2d& position, double angle, double scale):
	position(position),
	angle(angle),
	scale(scale) {}