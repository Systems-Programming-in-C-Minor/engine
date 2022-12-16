#ifndef ENGINE_CAMERA_HPP
#define ENGINE_CAMERA_HPP

#include "gameobject.hpp"
#include "color.hpp"

class Camera : public GameObject
{
private:

public:
    Color background_color;
    int aspect_width;
    int aspect_height;
    float mtp;

    Camera(int aspect_width = 100,
        int aspect_height = 100,
        bool is_world_space = true,
        Transform transform = Transform{},
        const Color& background_color = Color{},
        int mtp = 15.f
    );

    [[nodiscard]] Color get_background_color() const;
    void set_background_color(Color c);
    [[nodiscard]] int get_aspect_width() const;
    void set_aspect_width(int w);
    [[nodiscard]] int get_aspect_height() const;
    void set_aspect_height(int h);
};

#endif //ENGINE_CAMERA_HPP
