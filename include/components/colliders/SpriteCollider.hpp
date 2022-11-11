//
// Created by Laerositus on 11/11/2022.
//
#pragma once

#include "Collider.hpp"

class SpriteCollider : public Collider
{
    SpriteCollider();
    ~SpriteCollider();

    std::string m_path;

public:
    std::string get_path();
    void set_path(std::string p);
};