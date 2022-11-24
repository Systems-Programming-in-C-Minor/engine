#pragma once

#include <memory>
#include "component.hpp"
#include "vector2d.hpp"
#include "box2d/b2_shape.h"

enum class BodyType
{
    static_body,
    dynamic_body,
    kinematic_body
};

class RigidBody : public Component
{
    RigidBody();
    ~RigidBody();

    std::unique_ptr<b2MassData> _mass = std::make_unique<b2MassData>();
    double _gravity_scale;
    BodyType _bodytype;

public:
    void apply_force(Vector2d force);
    void apply_torque(float torque);
    void set_linear_velocity(Vector2d velocity);
    Vector2d get_linear_velocity();
    void set_angular_velocity(float angle);
    float get_angular_velocity();
    void apply_linear_impulse(Vector2d inpulse);
    void apply_angular_impulse(Vector2d impulse);

    [[nodiscard]] float get_mass() const;
    void set_mass(float m);
    [[nodiscard]] b2Vec2 get_center() const;
    void set_center(b2Vec2 center);
    [[nodiscard]] float get_rotational_inertia() const;
    void set_rotational_inertia(float i);
    double get_gravity_scale();
    void set_gravity_scale(double gs);
    BodyType get_bodytype();
    void set_bodytype(BodyType bt);

};
