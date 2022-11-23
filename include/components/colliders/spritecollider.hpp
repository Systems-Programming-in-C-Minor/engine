#ifndef COLLIDERS_SPRITECOLLIDER_HPP
#define COLLIDERS_SPRITECOLLIDER_HPP

#include "polygoncollider.hpp"

class SpriteCollider : public PolygonCollider
{
private:
    std::string _path;

public:
    SpriteCollider() = default;
    SpriteCollider(const std::string path);

    [[nodiscard]] std::string get_path() const;
    void set_path(std::string p);
};

#endif //COLLIDERS_SPRITECOLLIDER_HPP
