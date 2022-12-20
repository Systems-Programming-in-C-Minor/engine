#ifndef UTILS_TRIGONOMETRY_H_KXSSRBCSXL
#define UTILS_TRIGONOMETRY_H_KXSSRBCSXL

#include <cmath>

/**
 * @brief Method which calculates radians to degrees.
 * @param radians The radians which will be used for the calculation.
 * return Float value of the calculated degrees.
 */
inline static float radians_to_degrees(float radians)
{
	return(radians * (180 / M_PI));
}

/**
 * @brief Method which calculates degrees to radians.
 * @param degrees The degrees which will be used for the calculation.
 * return Float value of the calculated radians.
 */
inline static float degrees_to_radians(float degrees)
{
	return((degrees * M_PI) / 180);
}

/**
 * @brief Method which calculates radians to degrees.
 * @param radians The radians which will be used for the calculation.
 * return Double value of the calculated degrees.
 */
inline static double radians_to_degrees(double radians)
{
	return(radians * (180 / M_PI));
}

/**
 * @brief Method which calculates degrees to radians.
 * @param degrees The degrees which will be used for the calculation.
 * return Double value of the calculated radians.
 */
inline static double degrees_to_radians(double degrees)
{
	return((degrees * M_PI) / 180);
}

#endif // UTILS_TRIGONOMETRY_H_KXSSRBCSXL