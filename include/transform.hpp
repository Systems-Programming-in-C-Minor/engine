#ifndef ENGINE_TRANSFORM_H_sZYCcKEA4x
#define ENGINE_TRANSFORM_H_sZYCcKEA4x

#include <memory>

#include "vector2d.hpp"
#include "components/rigidbody.hpp"

class GameObject;

/**
 * @brief Instances of this class represent specific 2D transformations.
 */
class Transform {
private:
    Vector2d _position;
    Vector2d _local_position;
    float _angle;
    float _local_angle;
    float _scale;
    GameObject* _game_object = nullptr;

    friend class GameObject;

    /**
     * @brief Getter for the RigidBody of the Transform.
     * @return Return a shared pointer to the RigidBody object.
     */
    [[nodiscard]] std::shared_ptr<RigidBody> get_rigid_body() const;

public:
    /**
     * @brief Explicit constructor.
     * @param position The position of the Transform.
     * @param local_position The local position of the Transform.
     * @param angle The angle of the Transform (Rotation, in radians).
     * @param scale The scale of the Transform (Multiplication factor).
     */
    explicit Transform(const Vector2d &position = Vector2d{}, const Vector2d &local_position = Vector2d{},float angle = 0.f, float scale = 1.f);

    /**
     * @brief Getter for the angle of the Transform.
     * @return Return a float value of the current angle.
     */
    [[nodiscard]] float get_angle() const;

    /**
     * @brief Setter for the angle of the Transform.
     * @param angle The new angle which will be set.
     */
    void set_angle(float angle = 0.f);

    /**
     * @brief Getter for the scale of the Transform.
     * @return Return a float value of the current scale.
     */
    [[nodiscard]] float get_scale() const;

    /**
     * @brief Setter for the scale of the Transform.
     * @param scale The new scale which will be set.
     */
    void set_scale(float scale = 1.f);

    /**
     * @brief Getter for the position of the Transform.
     * @return Return a Vector2d value of the current position.
     */
    [[nodiscard]] Vector2d get_position() const;

    /**
     * @brief Setter for the position of the Transform.
     * @param position The new position which will be set.
     */
    void set_position(Vector2d &position);

    /**
     * @brief Getter for the local position of the Transform.
     * @return Return a Vector2d value of the current local position.
     */
    [[nodiscard]] Vector2d get_local_position() const;

    /**
     * @brief Setter for the local position of the Transform.
     * @param new_position The new local position which will be set.
     */
    void set_local_position(Vector2d &new_position);

    /**
     * @brief Getter for the local angle of the Transform.
     * @return Return a float value of the current local angle.
     */
    [[nodiscard]] float get_local_angle() const;

    /**
     * @brief Setter for the local angle of the Transform.
     * @param angle The new local angle which will be set.
     */
    void set_local_angle(float &angle);
};

#endif // ENGINE_TRANSFORM_H_sZYCcKEA4x
