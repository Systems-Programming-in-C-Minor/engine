#ifndef COLLIDERS_BOXCOLLIDER_HPP
#define COLLIDERS_BOXCOLLIDER_HPP

#include "polygoncollider.hpp"

class BoxCollider : public PolygonCollider
{
private:
    double _width;
    double _height;

public:
    BoxCollider(double width = 1.0, double height = 1.0);

    [[nodiscard]] double get_width() const;
    [[nodiscard]] double get_height() const;
};

#endif //COLLIDERS_BOXCOLLIDER_HPP