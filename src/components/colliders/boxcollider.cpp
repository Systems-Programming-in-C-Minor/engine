#include "components/colliders/boxcollider.hpp"

BoxCollider::BoxCollider(double width, double height) :
	PolygonCollider(std::vector<Vector2d>{
		Vector2d{-width * .5, height * .5 },
		Vector2d{width * .5, height * .5 },
		Vector2d{width * .5, -height * .5},
		Vector2d{-width * .5, -height * .5}
	}),
	_width(width), _height(height) {}
	
double BoxCollider::get_width() const {
    return _width;
}

double BoxCollider::get_height() const {
    return _height;
}


