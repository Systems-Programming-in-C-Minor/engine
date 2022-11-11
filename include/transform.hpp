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

	Transform(const Vector2d& position, double angle = 0.0, double scale = 0.0);
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
