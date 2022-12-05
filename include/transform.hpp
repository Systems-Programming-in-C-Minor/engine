#ifndef ENGINE_TRANSFORM_H_sZYCcKEA4x
#define ENGINE_TRANSFORM_H_sZYCcKEA4x

#include <memory>

#include "vector2d.hpp"
#include "interfaces/itickable.hpp"

class Transform : public ITickable {
private:
    Vector2d _position;
    float _angle;
    float _scale;

public:
    explicit Transform(const Vector2d &position, float angle = 0.f, float scale = 1.f);

    [[nodiscard]] float get_angle() const;

    void set_angle(float angle = 0.f);

    [[nodiscard]] float get_scale() const;

    void set_scale(float scale = 1.f);

    [[nodiscard]] Vector2d get_position() const;

    void set_position(Vector2d &position);

    void tick(GameObject &object) override;
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
