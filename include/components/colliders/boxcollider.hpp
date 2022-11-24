#ifndef COLLIDERS_BOXCOLLIDER_HPP
#define COLLIDERS_BOXCOLLIDER_HPP

#include "polygoncollider.hpp"

class BoxCollider : public PolygonCollider
{
private:
    float _width;
    float _height;

public:
    BoxCollider(float width, float height);

    [[nodiscard]] float get_width() const;
    [[nodiscard]] float get_height() const;
};

#endif //COLLIDERS_BOXCOLLIDER_HPP