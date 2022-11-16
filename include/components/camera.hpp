#pragma once

#include "gameobject.hpp"
#include "color.hpp"

class Camera : public GameObject
{
private:
    Camera(std::string name, std::string tag, int aspect_width, int aspect_height);
    ~Camera();

    Color _background_color;
    int _aspect_width;
    int _aspect_height;

public:
    Color get_background_color();
    void set_background_color(Color c);
    int get_aspect_width();
    void set_aspect_width(int w);
    int get_aspect_height();
    void set_aspect_height(int h);
};
