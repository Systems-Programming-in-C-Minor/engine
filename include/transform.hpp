#ifndef ENGINE_TRANSFORM_H_sZYCcKEA4x
#define ENGINE_TRANSFORM_H_sZYCcKEA4x

#include <memory>

#include "vector2d.hpp"
#include "interfaces/itickable.hpp"

class Transform : public ITickable {
private:
    Vector2d _position;
    double _angle;
    double _scale;

public:
    explicit Transform(const Vector2d &position, double angle = 0.0, double scale = 0.0);

    [[nodiscard]] double get_angle() const;

    void set_angle(double angle = 0.0);

    [[nodiscard]] double get_scale() const;

    void set_scale(double scale = 1.0);

    [[nodiscard]] Vector2d get_position() const;

    void set_position(Vector2d &position);

    void tick(GameObject &object) override;
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
