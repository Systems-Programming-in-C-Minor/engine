#include "components/colliders/boxcollider.hpp"

BoxCollider::BoxCollider(float width, float height, bool ignore_collision_physics) :
	PolygonCollider(std::vector<Vector2d>{
		Vector2d{-width * .5f, height * .5f },
		Vector2d{width * .5f, height * .5f },
		Vector2d{width * .5f, -height * .5f},
		Vector2d{-width * .5f, -height * .5f}
	}, ignore_collision_physics),
	_width(width), _height(height) {}
	
float BoxCollider::get_width() const {
    return _width;
}

float BoxCollider::get_height() const {
    return _height;
}
