#ifndef RIGID_BODY_HPP
#define RIGID_BODY_HPP

#include "component.hpp"
#include "vector2d.hpp"
#include "memory"
#include "interfaces/irenderable.hpp"

enum class BodyType {
    static_body = 0,
    kinematic_body,
    dynamic_body
};

class b2Body;

class b2Vec2;

class Scene;
class Collider;
class SdlRenderer;

class RigidBody : public Component, public IRenderable {
    friend class SdlRenderer;
public:
    RigidBody(const Scene &scene,
        int order_in_layer,
        const BodyType type, 
        const Vector2d vector, 
        const float gravity_scale, 
        float restitution = 0.5f, 
        float friction = 0.5f
    );

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

    void set_position(Vector2d vector) const;

    [[nodiscard]] Vector2d get_position() const;

    void set_angle(float angle) const;

    [[nodiscard]] float get_angle() const;

    void set_collider(std::shared_ptr<Collider> collider);

    void render(bool is_world_space) const override;

private:
    b2Body *_body;
    std::shared_ptr<Collider> _collider;    
    float _restitution;
    float _friction;

    [[nodiscard]] b2Body* get_body() const;

    static b2Vec2 get_b2vec(Vector2d vector);

    static Vector2d get_vec(b2Vec2 vector);
};

#endif //RIGID_BODY_HPP