#ifndef ENGINE_CAMERA_HPP
#define ENGINE_CAMERA_HPP

#include "gameobject.hpp"
#include "color.hpp"

class Camera : public GameObject
{
public:
    Color background_color;
    float mtp;
    float screen_space_limits;

    Camera(
        Transform transform = Transform{},
        const Color& background_color = Color{},
        float mtp = 15.f,
        float screen_space_limits = 200.f
    );

    [[nodiscard]] Color get_background_color() const;
    void set_background_color(Color c);
};

#endif //ENGINE_CAMERA_HPP
