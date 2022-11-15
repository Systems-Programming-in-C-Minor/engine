#pragma once

#include "collider.hpp"

class CircleCollider : public Collider
{
    CircleCollider();
    ~CircleCollider();

    double _radius;

public:
    double get_radius();
    void set_radius(double r);
};

