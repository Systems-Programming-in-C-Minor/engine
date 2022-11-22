#include "components/colliders/polygoncollider.hpp"

PolygonCollider::PolygonCollider() : Collider() {}

PolygonCollider::PolygonCollider(std::vector<Vector2d> points) : Collider(){
    _points = std::move(points);
}

std::vector<Vector2d> PolygonCollider::get_points() const {
    return _points;
}

void PolygonCollider::set_points(std::vector<Vector2d> p){
    _points = p;
}
