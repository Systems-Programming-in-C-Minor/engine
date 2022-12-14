#ifndef ENGINE_TRANSFORM_H_sZYCcKEA4x
#define ENGINE_TRANSFORM_H_sZYCcKEA4x

#include <memory>

#include "vector2d.hpp"
#include "components/rigidbody.hpp"

class GameObject;

class Transform {
private:
    Vector2d _position;
    Vector2d _local_position;
    float _angle;
    float _local_angle;
    float _scale;
    GameObject* _game_object = nullptr;

    friend class GameObject;

    [[nodiscard]] std::shared_ptr<RigidBody> get_rigid_body() const;

public:
    explicit Transform(const Vector2d &position = Vector2d{}, const Vector2d &local_position = Vector2d{},float angle = 0.f, float scale = 1.f);

    [[nodiscard]] float get_angle() const;

    void set_angle(float angle = 0.f);

    [[nodiscard]] float get_scale() const;

    void set_scale(float scale = 1.f);

    [[nodiscard]] Vector2d get_position() const;

    void set_position(Vector2d &position);

    [[nodiscard]] Vector2d get_local_position() const;

    void set_local_position(Vector2d &new_position);

    [[nodiscard]] float get_local_angle() const;

    void set_local_angle(float &angle);
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
