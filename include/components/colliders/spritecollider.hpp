#pragma once

#include "collider.hpp"

class SpriteCollider : public Collider
{
private:

    std::string _path;

public:
    SpriteCollider() {};
    ~SpriteCollider() = default;
    std::string get_path();
    void set_path(std::string p);
};
