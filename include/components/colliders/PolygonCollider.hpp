//
// Created by Laerositus on 11/11/2022.
//
#pragma once

//#include "Vector2d.hpp"
#include "Collider.hpp"

#include <vector>

class Vector2d;

class PolygonCollider : public Collider
{
    PolygonCollider();
    ~PolygonCollider();

    std::vector<Vector2d> m_points;

public:
//    std::vector<Vector2d> get_points();
//    void set_points(std::vector<Vector2d> p);
};