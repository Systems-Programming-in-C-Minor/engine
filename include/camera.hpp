#ifndef COMPONENTS_CAMERA_HPP
#define COMPONENTS_CAMERA_HPP

#include "gameobject.hpp"
#include "color.hpp"

class Camera : public GameObject
{
private:
    Color _background_color;
    int _aspect_width;
    int _aspect_height;

public:
    Camera(int aspect_width, int aspect_height);

    [[nodiscard]] Color get_background_color() const ;
    void set_background_color(Color c);
    [[nodiscard]] int get_aspect_width() const ;
    void set_aspect_width(int w);
    [[nodiscard]] int get_aspect_height() const ;
    void set_aspect_height(int h);
};

#endif //COMPONENTS_CAMERA_HPP
