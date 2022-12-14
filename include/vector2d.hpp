#ifndef ENGINE_VECTOR2D_H_PgDkltz57P
#define ENGINE_VECTOR2D_H_PgDkltz57P

#include <ostream>

struct b2Vec2;
class PolygonCollider;
class ChainCollider;
class SdlRenderer;

class Vector2d {
public:
    float x, y;

    [[nodiscard]] Vector2d add(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator+(const Vector2d &other) const;

    [[nodiscard]] Vector2d subtract(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator-(const Vector2d &other) const;

    [[nodiscard]] Vector2d multiply(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator*(const Vector2d &other) const;

    [[nodiscard]] Vector2d divide(const Vector2d &other) const;
    [[nodiscard]] Vector2d operator/(const Vector2d &other) const;

    [[nodiscard]] Vector2d multiply(float other) const;
    [[nodiscard]] Vector2d operator*(float other) const;

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

    [[nodiscard]] float length() const;

    float normalize() const;

    [[nodiscard]] float static dot(const Vector2d &a, const Vector2d &b);

    [[nodiscard]] float cross(const Vector2d &a, const Vector2d &b);

    [[nodiscard]] float static angle(const Vector2d &from, const Vector2d &to);

    [[nodiscard]] float static signed_angle(const Vector2d &from, const Vector2d &to, const Vector2d &axis);

    [[nodiscard]] float static distance(const Vector2d &a, const Vector2d &b);

    explicit Vector2d(float x = 0.0f, float y = 0.0f);
private:
    friend class PolygonCollider;
    friend class ChainCollider;
    friend class SdlRenderer;
    explicit Vector2d(const b2Vec2& b2vec);
    explicit operator b2Vec2() const;
};

std::ostream &operator<<(std::ostream &stream, const Vector2d &vector);

#endif // ENGINE_VECTOR2D_H_PgDkltz57P