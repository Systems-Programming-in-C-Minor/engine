#pragma once

#include "Collider.hpp"

class CircleCollider : public Collider
{
    CircleCollider();
    ~CircleCollider();

    double m_radius;

public:
    double get_radius();
    void set_radius(double r);
};

