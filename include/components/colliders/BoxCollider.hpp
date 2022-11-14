#pragma once

#include "Collider.hpp"

class BoxCollider : public Collider
{
    BoxCollider();
    ~BoxCollider();

    double _width;
    double _height;

public:
    double get_width();
    void set_width(double w);
    double get_height();
    void set_height(double h);

};
