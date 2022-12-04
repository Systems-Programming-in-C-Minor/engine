#ifndef UTILS_TRIGONOMETRY_H_KXSSRBCSXL
#define UTILS_TRIGONOMETRY_H_KXSSRBCSXL

#include <cmath>

inline static double radians_to_degrees(double radians)
{
	return(radians * (180 / M_PI));
}

inline static double degrees_to_radians(double degrees)
{
	return((degrees * M_PI) / 180);
}

#endif // UTILS_TRIGONOMETRY_H_KXSSRBCSXL