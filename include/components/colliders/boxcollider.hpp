#ifndef COLLIDERS_BOXCOLLIDER_HPP
#define COLLIDERS_BOXCOLLIDER_HPP

#include "collider.hpp"
#include "polygoncollider.hpp"

class BoxCollider : public PolygonCollider
{
private:
    double _width;
    double _height;

public:
    [[nodiscard]] double get_width() const;
    void set_width(double w);
    [[nodiscard]] double get_height() const;
    void set_height(double h);

};
#endif //COLLIDERS_BOXCOLLIDER_HPP