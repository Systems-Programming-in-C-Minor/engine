#pragma once

#include "collider.hpp"
#include "polygoncollider.hpp"

class BoxCollider : public PolygonCollider
{
private:

    double _width;
    double _height;

public:
    BoxCollider() {};
    ~BoxCollider() = default;

    double get_width();
    void set_width(double w);
    double get_height();
    void set_height(double h);

};
