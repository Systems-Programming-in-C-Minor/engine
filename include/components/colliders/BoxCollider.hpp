#pragma once

#include "Collider.hpp"

class BoxCollider : public Collider
{
    BoxCollider();
    ~BoxCollider();

    double m_width;
    double m_height;

public:
    double get_width();
    void set_width(double w);
    double get_height();
    void set_height(double h);

};
