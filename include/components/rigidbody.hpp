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

class b2Vec2;

class Scene;

class RigidBody : public Component {
public:
    RigidBody(const Scene &scene, BodyType type, Vector2d vector, float gravity_scale);

    void apply_force(Vector2d force, Vector2d point) const;

    void apply_torque(float torque) const;

    void set_linear_velocity(Vector2d velocity) const;

    [[nodiscard]] Vector2d get_linear_velocity() const;

    void set_angular_velocity(float angle) const;

    [[nodiscard]] float get_angular_velocity() const;

    void apply_linear_impulse(Vector2d impulse, Vector2d point) const;

    void apply_angular_impulse(float impulse) const;

    [[nodiscard]] float get_mass() const;

    [[nodiscard]] float get_inertia() const;

    void set_mass(float mass) const;

    [[nodiscard]] float get_gravity_scale() const;

    void set_gravity_scale(float gravity_scale) const;

    [[nodiscard]] BodyType get_body_type() const;

    void set_body_type(BodyType body_type) const;

    [[nodiscard]] Vector2d get_world_position() const;

private:
    b2Body *_body;

    static b2Vec2 get_b2vec(Vector2d vector);

    static Vector2d get_vec(b2Vec2 vector);
};

#endif //RIGID_BODY_HPP