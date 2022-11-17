#pragma once

#include "collider.hpp"

class BoxCollider : public PolygonCollider
{
private:
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
