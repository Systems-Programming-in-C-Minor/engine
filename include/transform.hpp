#ifndef ENGINE_TRANSFORM_H_sZYCcKEA4x
#define ENGINE_TRANSFORM_H_sZYCcKEA4x

#include <memory>

#include "vector2d.hpp"

class Transform
{
public:
	[[nodiscard]] float get_angle() const;
	void set_angle(float angle = 0.f);
	[[nodiscard]] float get_scale() const;
	void set_scale(float scale = 1.f);
	[[nodiscard]] Vector2d get_position() const;
	void set_position(const Vector2d& position);

	Transform(const Vector2d& position, float angle = 0.f, float scale = 1.f);

private:
	Vector2d _position;
	float _angle;
	float _scale;
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
