#ifndef ENGINE_JSON_CONVERTERS
#define ENGINE_JSON_CONVERTERS

#include <nlohmann/json.hpp>
#include "vector2d.hpp"
#include "transform.hpp"

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Vector2d, x, y)

inline void to_json(nlohmann::json &j, const Transform &t) {
    j = nlohmann::json{
            {"angle",          t.get_angle()},
            {"scale",          t.get_scale()},
            {"position",       t.get_position()},
            {"local_position", t.get_local_position()},
            {"local_angle",    t.get_local_angle()},
    };
}

inline void from_json(const nlohmann::json &j, Transform &t) {
    t.set_angle(j.at("angle").get<float>());
    t.set_scale(j.at("scale").get<float>());
    t.set_position(j.at("position").get<Vector2d>());
    t.set_local_position(j.at("local_position").get<Vector2d>());
    t.set_local_angle(j.at("local_angle").get<float>());
}

#endif // ENGINE_JSON_CONVERTERS
