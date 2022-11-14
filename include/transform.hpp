#ifndef ENGINE_TRANSFORM_H_sZYCcKEA4x
#define ENGINE_TRANSFORM_H_sZYCcKEA4x

#include <memory>

#include "vector2d.hpp"

class Transform
{
public:
	Vector2d position;
	double angle;
	double scale;

	double get_angle();
	void set_angle(double angle = 0.0);
	double get_scale();
	void set_scale(double scale = 1.0);

	Transform(const Vector2d& position, double angle = 0.0, double scale = 0.0);
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
