#pragma once

#include "GameObject.hpp"

class Color {
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 1;
};

class Camera : public GameObject
{
    Color m_background_color;
    int m_aspect_width;
    int m_aspect_height;

public:
    Color get_background_color();
    void set_background_color(Color c);
    int get_aspect_width();
    void set_aspect_width(int w);
    int get_aspect_height();
    void set_aspect_height(int h);
};
