#pragma once
#include "component.hpp"
#include "vector2d.hpp"

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

    double _mass;
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

    double get_mass();
    void set_mass(double m);
    double get_gravity_scale();
    void set_gravity_scale(double gs);
    BodyType get_bodytype();
    void set_bodytype(BodyType bt);

};
