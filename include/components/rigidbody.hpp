#ifndef RIGID_BODY_HPP
#define RIGID_BODY_HPP

#include "component.hpp"
#include "vector2d.hpp"
#include "memory"
#include "interfaces/irenderable.hpp"

/**
 * @brief Enumeration for different rigid body types.
 */
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

/**
 * @brief A component representing a rigid body.
 */
class RigidBody : public Component, public IRenderable {
    /**
    * @brief The SdlRenderer friend class.
    */
    friend class SdlRenderer;
public:
    /**
     * @brief Constructor.
     * @param order_in_layer The order in which the rigid body is rendered.
     * @param type The BodyType of the rigid body.
     * @param vector The Vector2d of the rigid body.
     * @param gravity_scale The initial gravity scale of the rigid body.
     * @param restitution The initial restitution of the rigid body.
     * @param friction The initial friction of the rigid body.
     */
    RigidBody(const Scene &scene,
        int order_in_layer,
        BodyType type,
        Vector2d vector,
        float gravity_scale = 1.0f,
        float restitution = 0.5f, 
        float friction = 0.5f
    );

    /**
     * @brief Apply force to this rigid body.
     * @param force	the world force vector, usually in Newtons (N).
     * @param point the world position of the point of application.
     */
    void apply_force(Vector2d force, Vector2d point) const;

    /**
     * @brief Apply a torque. This affects the angular velocity without affecting the linear velocity of the center of mass.
     * @param torque about the z-axis (out of the screen), usually in N-m.
     */
    void apply_torque(float torque) const;

    /**
     * @brief Set new linear_velocity.
     * @param velocity The new linear_velocity.
     */
    void set_linear_velocity(Vector2d velocity) const;

    /**
     * @brief Getter for the linear_velocity.
     * @return the current linear_velocity.
     */
    [[nodiscard]] Vector2d get_linear_velocity() const;


    /**
     * @brief Set new angular_velocity.
     * @param angle The new angular_velocity.
     */
    void set_angular_velocity(float angle) const;

    /**
     * @brief Getter for the angular_velocity.
     * @return the current angular_velocity.
     */
    [[nodiscard]] float get_angular_velocity() const;

    /**
     * @brief Apply an impulse at a point. This immediately modifies the velocity.
     * @param impulse about the z-axis (out of the screen), usually in N-m.
     * @param point the world position of the point of application.
     */
    void apply_linear_impulse(Vector2d impulse, Vector2d point) const;

    /**
     * @brief Apply an angular impulse.
     * @param impulse the angular impulse in units of kg*m*m/s.
     */
    void apply_angular_impulse(float impulse) const;

    /**
     * @brief Getter for the world vector.
     * @return the current world vector.
     */
    [[nodiscard]] Vector2d get_world_vector(Vector2d vector) const;

    /**
     * @brief Getter for the lateral velocity.
     * @return the current lateral velocity.
     */
    Vector2d get_lateral_velocity();

    /**
     * @brief Getter for the forward velocity.
     * @return the current forward velocity.
     */
    Vector2d get_forward_velocity();

    /**
     * @brief Getter for the direction.
     * @return the current direction.
     */
    Vector2d get_direction();

    /**
     * @brief Getter for the current speed.
     * @return the current speed.
     */
    float get_current_speed();

    /**
     * @brief Getter for the world center.
     * @return the current world center.
     */
    Vector2d get_world_center();

    /**
     * @brief Set new mass.
     * @param mass The new mass.
     */
    void set_mass(float mass) const;

    /**
     * @brief Getter for the current mass.
     * @return the current mass.
     */
    [[nodiscard]] float get_mass() const;

    /**
     * @brief Getter for the inertia.
     * @return the current inertia.
     */
    [[nodiscard]] float get_inertia() const;

    /**
     * @brief Getter for the gravity_scale.
     * @return the current gravity_scale.
     */
    [[nodiscard]] float get_gravity_scale() const;

    /**
     * @brief Set new gravity_scale.
     * @param gravity_scale The new gravity_scale.
     */
    void set_gravity_scale(float gravity_scale) const;

    /**
     * @brief Getter for the body_type.
     * @return the current body_type.
     */
    [[nodiscard]] BodyType get_body_type() const;

    /**
     * @brief Set new body_type.
     * @param body_type The new body_type.
     */
    void set_body_type(BodyType body_type) const;

    /**
     * @brief Set new position.
     * @param vector The new position.
     */
    void set_position(Vector2d vector) const;

    /**
     * @brief Getter for the current position.
     * @return the current position.
     */
    [[nodiscard]] Vector2d get_position() const;

    /**
     * @brief Set the new angle.
     * @param angle The new angle.
     */
    void set_angle(float angle) const;

    /**
     * @brief Getter for the current angle.
     * @return the current angle.
     */
    [[nodiscard]] float get_angle() const;

    /**
     * @brief Set the collider.
     * @param collider A shared pointer to the new collider.
     */
    void set_collider(const std::shared_ptr<Collider>& collider);

    /**
     * @brief Render the rigid body.
     */
    void render() override;

private:
    b2Body *_body;
    std::shared_ptr<Collider> _collider;
    float _restitution;
    float _friction;

    /**
     * @brief Getter for the current b2Body.
     * @return a pointer to the current b2Body.
     */
    [[nodiscard]] b2Body* get_body() const;

    /**
     * @brief Getter for the current b2Vec.
     * @return The current b2Vec.
     */
    static b2Vec2 get_b2vec(Vector2d vector);

    /**
     * @brief Getter for the current Vector2d.
     * @return The current Vector2d.
     */
    static Vector2d get_vec(b2Vec2 vector);
};

#endif //RIGID_BODY_HPP