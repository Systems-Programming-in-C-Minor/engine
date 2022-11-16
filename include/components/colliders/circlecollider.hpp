#pragma once

#include "collider.hpp"

class CircleCollider : public Collider
{
private:
    CircleCollider();
    ~CircleCollider();

    double _radius;

public:
    double get_radius();
    void set_radius(double r);
};

