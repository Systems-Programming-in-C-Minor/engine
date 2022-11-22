#pragma once

#include "collider.hpp"

class SpriteCollider : public Collider
{
private:
    std::string _path;

public:
    SpriteCollider() = default;
    explicit SpriteCollider(std::string path);

    [[nodiscard]] std::string get_path() const;
    void set_path(std::string p);
};
