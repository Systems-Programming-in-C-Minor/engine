#ifndef ENGINE_VECTOR2D_H_PgDkltz57P
#define ENGINE_VECTOR2D_H_PgDkltz57P

#include <ostream>

struct b2Vec2;
class PolygonCollider;
class ChainCollider;
class SdlRenderer;

namespace SDL2pp
{
    class Point;
}

/**
 * @brief Class representing a 2D vector.
 */
class Vector2d {
    /**
    * @brief The PolygonCollider friend class.
    */
    friend class PolygonCollider;

    /**
    * @brief The ChainCollider friend class.
    */
    friend class ChainCollider;

    /**
    * @brief The SdlRenderer friend class.
    */
    friend class SdlRenderer;
public:

    /**
    * @brief The x position of the Vector2d.
    */
    float x;

    /**
    * @brief The y position of the Vector2d.
    */
    float y;

    /**
     * @brief Method which adds 2 Vector2d objects.
     * @param other The Vector2d object which will be added to the current one.
     * @return The new Vector2d object.
     */
    [[nodiscard]] Vector2d add(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator+(const Vector2d &other) const;

    /**
     * @brief Method which subtracts 2 Vector2d objects.
     * @param other The Vector2d object which will be subtracted from the current one.
     * @return The new Vector2d object.
     */
    [[nodiscard]] Vector2d subtract(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator-(const Vector2d &other) const;

    /**
     * @brief Method which multiplies 2 Vector2d objects.
     * @param other The Vector2d object which will be multiplied with the current one.
     * @return The new Vector2d object.
     */
    [[nodiscard]] Vector2d multiply(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator*(const Vector2d &other) const;

    /**
     * @brief Method which divides 2 Vector2d objects.
     * @param other The Vector2d object which will be divides from the current one.
     * @return The new Vector2d object.
     */
    [[nodiscard]] Vector2d divide(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator/(const Vector2d &other) const;

    /**
     * @brief Method which multiplies the objects' x and y value with a given float value.
     * @param other The float value which will be used for the multiplication.
     * @return The new Vector2d object.
     */
    [[nodiscard]] Vector2d multiply(float other) const;
    [[nodiscard]] Vector2d operator*(float other) const;

    /**
     * @brief Method which divides the objects' x and y value with a given float value.
     * @param other The float value which will be used for the division.
     * @return The new Vector2d object.
     */
    [[nodiscard]] Vector2d divide(float other) const;
    [[nodiscard]] Vector2d operator/(float other) const;

    /**
     * Checks equality of the vector
     *
     * @param[in] other Vector2d to check for equality
     *
     * @return true if equal
     * @return false if not equal
     */
    [[nodiscard]] bool equals(const Vector2d &other) const;
    [[nodiscard]] bool operator==(const Vector2d &other) const;

    /**
     * Checks equality of the vector given an epsilon
     *
     * @param[in] other Vector2d to check for equality
     * @param[in] epsilon Epsilon to be used for the equality check
     *
     * @return true if equal
     * @return false if not equal
     */
    [[nodiscard]] bool almost_equals(const Vector2d &other, double epsilon) const;

    /**
     * @brief Method which returns the length of the Vector2d object.
     * @return The new Vector2d's length.
     */
    [[nodiscard]] float length() const;

    /**
     * @brief Method which returns the normalized length of the Vector2d object.
     * @return The new Vector2d's normalized length.
     */
    [[nodiscard]] float normalized_length() const;

    /**
     * @brief Method which normalizes the Vector2d.
     * @return The float value of the normalized Vector2d.
     */
    float normalize();

    /**
     * @brief Method which returns the dot product of 2 Vector2ds.
     * @param a The first Vector2d object which will be used for the calculation.
     * @param b he second Vector2d object which will be used for the calculation.
     * @return The float value of the dot product.
     */
    [[nodiscard]] float static dot(const Vector2d &a, const Vector2d &b);

    /**
     * @brief Method which returns the cross product of 2 Vector2ds.
     * @param a The first Vector2d object which will be used for the calculation.
     * @param b he second Vector2d object which will be used for the calculation.
     * @return The float value of the cross product.
     */
    [[nodiscard]] float cross(const Vector2d &a, const Vector2d &b);

    /**
     * @brief Method which returns the angle between 2 Vector2ds.
     * @param from The first Vector2d object which will be used for the calculation.
     * @param to he second Vector2d object which will be used for the calculation.
     * @return The float value of the angle.
     */
    [[nodiscard]] float static angle(const Vector2d &from, const Vector2d &to);

    /**
     * @brief Method which returns the signed angle between 2 Vector2ds.
     * @param from The first Vector2d object which will be used for the calculation.
     * @param to he second Vector2d object which will be used for the calculation.
     * @return The float value of the signed angle.
     */
    [[nodiscard]] float static signed_angle(const Vector2d &from, const Vector2d &to, const Vector2d &axis);

    /**
     * @brief Method which returns the distance between 2 Vector2ds.
     * @param from The first Vector2d object which will be used for the calculation.
     * @param to he second Vector2d object which will be used for the calculation.
     * @return The float value of the distance.
     */
    [[nodiscard]] float static distance(const Vector2d &a, const Vector2d &b);

    /**
     * @brief Explicit constructor.
     * @param x The x value of the Vector2d object.
     * @param y The y value of the Vector2d object.
     */
    explicit Vector2d(float x = 0.0f, float y = 0.0f);
private:
    /**
     * @brief Explicit constructor.
     * @param b2vec The b2Vec object from which the x and y values will be copied.
     */
    explicit Vector2d(const b2Vec2& b2vec);

    /**
     * @brief Method which casts a b2Vec to a Vector2d.
     */
    explicit operator b2Vec2() const;

    /**
     * @brief Explicit constructor.
     * @param point The SDL2pp::Point object from which the x and y values will be copied.
     */
    explicit Vector2d(const SDL2pp::Point& point);

    /**
     * @brief Method which casts a SDL2pp::Point to a Vector2d.
     */
    explicit operator SDL2pp::Point() const;
};

std::ostream &operator<<(std::ostream &stream, const Vector2d &vector);

#endif // ENGINE_VECTOR2D_H_PgDkltz57P