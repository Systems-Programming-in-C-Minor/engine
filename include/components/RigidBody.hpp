#ifndef ENGINE_RIGIDBODY_HPP
#define ENGINE_RIGIDBODY_HPP

#include "Component.hpp"
//#include "Vector2d"
class Vector2d; // TODO Replace with above include statement.

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

    double m_mass;
    double m_gravity_scale;
    BodyType m_bodytype;

public:
//    void apply_force(Vector2d force);
//    void apply_torque(float torque);
//    void set_linear_velocity(Vector2d velocity);
//    Vector2d get_linear_velocity();
//    void set_angular_velocity(float angle);
//    float get_angular_velocity();
//    void apply_linear_impulse(Vector2d inpulse);
//    void apply_angular_impulse(Vector2d impulse);

    double get_mass();
    void set_mass(double m);
    double get_gravity_scale();
    void set_gravity_scale(double gs);
    BodyType get_bodytype();
    void set_bodytype(BodyType bt);

};

#endif //ENGINE_RIGIDBODY_HPP
