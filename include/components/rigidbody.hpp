#pragma once

#include "component.hpp"
#include "vector2d.hpp"
#include "memory"

enum class BodyType {
    static_body = 0,
    kinematic_body,
    dynamic_body
};

class b2Body;

class b2Vec2;

class Scene;

class RigidBody : public Component {
public:

    /**
    * @param body
    */
    RigidBody(Scene &scene, BodyType type, Vector2d vector, float gravity_scale);

    void apply_force(Vector2d force);

    void apply_torque(float torque);

    void set_linear_velocity(Vector2d velocity);

    Vector2d get_linear_velocity();

    void set_angular_velocity(float angle);

    float get_angular_velocity();

    void apply_linear_impulse(Vector2d impulse, Vector2d point);

    void apply_angular_impulse(float impulse);

    float get_mass();

    float get_inertia();

    void set_mass(float mass);

    float get_gravity_scale();

    void set_gravity_scale(float gravity_scale);

    BodyType get_body_type();

    void set_body_type(BodyType bt);

private:
    b2Body *_body;

    static b2Vec2 get_b2vec(Vector2d vector);

    static Vector2d get_vec(b2Vec2 vector);
};
