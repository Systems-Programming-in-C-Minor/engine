#ifndef ENGINE_VECTOR2D_H_PgDkltz57P
#define ENGINE_VECTOR2D_H_PgDkltz57P

#include <ostream>

class Vector2d
{
public:
	double x, y;

	Vector2d add(const Vector2d& other) const;
	Vector2d operator+(const Vector2d& other) const;

	Vector2d subtract(const Vector2d& other) const;
	Vector2d operator-(const Vector2d& other) const;

	Vector2d multiply(const Vector2d& other) const;
	Vector2d operator*(const Vector2d& other) const;

	Vector2d divide(const Vector2d& other) const;
	Vector2d operator/(const Vector2d& other) const;

	/**
	 * Checks equality of the vector
	 * 
	 * @param[in] other Vector2d to check for equality
	 * 
	 * @return true if equal
	 * @return false if not equal
	 */
	bool equals(const Vector2d& other) const;
	bool operator==(const Vector2d& other) const;

	/**
	 * Checks equality of the vector given an epsilon
	 * 
	 * @param[in] other Vector2d to check for equality
	 * @param[in] epsilon Epsilon to be used for the equality check
	 * 
	 * @return true if equal 
	 * @return false if not equal
	 */
	bool almost_equals(const Vector2d& other, const double epsilon) const;

	Vector2d(const double x=0.0, const double y=0.0);
};

std::ostream& operator<<(std::ostream& stream, const Vector2d& vector);

#endif // ENGINE_VECTOR2D_H_PgDkltz57P