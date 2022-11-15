#pragma once

#include "collider.hpp"

class SpriteCollider : public Collider
{
    SpriteCollider();
    ~SpriteCollider();

    std::string _path;

public:
    std::string get_path();
    void set_path(std::string p);
};
