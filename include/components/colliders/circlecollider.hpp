#pragma once

#include "collider.hpp"

class CircleCollider : public Collider
{
private:
    double _radius;

public:
    [[nodiscard]] double get_radius() const;
    void set_radius(double r);
};

