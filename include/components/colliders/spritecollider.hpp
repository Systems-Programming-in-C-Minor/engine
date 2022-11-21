#pragma once

#include "collider.hpp"

class SpriteCollider : public Collider
{
private:
    std::string _path;

public:
    SpriteCollider() = default;
    explicit SpriteCollider(std::string path);

    ~SpriteCollider() = default;
    std::string get_path();
    void set_path(std::string p);
};
