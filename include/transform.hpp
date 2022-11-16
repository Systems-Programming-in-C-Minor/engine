#ifndef ENGINE_TRANSFORM_H_sZYCcKEA4x
#define ENGINE_TRANSFORM_H_sZYCcKEA4x

#include <memory>

#include "vector2d.hpp"

class Transform
{
public:
	double get_angle();
	void set_angle(double angle = 0.0);
	double get_scale();
	void set_scale(double scale = 1.0);
	Vector2d get_position();
	void set_position(Vector2d& position);

	Transform(const Vector2d& position, double angle = 0.0, double scale = 0.0);

private:
	Vector2d _position;
	double _angle;
	double _scale;
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
