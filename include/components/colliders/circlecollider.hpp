#pragma once

#include "collider.hpp"

class CircleCollider : public Collider
{
private:



    double _radius;

public:
    CircleCollider() {};
    ~CircleCollider() = default;

    double get_radius();
    void set_radius(double r);
};

