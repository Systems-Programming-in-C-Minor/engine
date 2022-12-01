#ifndef RIGID_BODY_HPP
#define RIGID_BODY_HPP

#include "component.hpp"
#include "vector2d.hpp"
#include "memory"

enum class BodyType {
    static_body = 0,
    kinematic_body,
    dynamic_body
};

class b2Body;

class Scene;

class RigidBody : public Component {
public:

    RigidBody(Scene &scene, BodyType type, Vector2d vector, double gravity_scale);

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

private:
    b2Body *_body;
};

#endif //RIGID_BODY_HPP