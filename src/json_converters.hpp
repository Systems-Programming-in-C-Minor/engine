#ifndef ENGINE_JSON_CONVERTERS
#define ENGINE_JSON_CONVERTERS

#include <nlohmann/json.hpp>
#include "vector2d.hpp"

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Vector2d, x, y)

#endif // ENGINE_JSON_CONVERTERS
