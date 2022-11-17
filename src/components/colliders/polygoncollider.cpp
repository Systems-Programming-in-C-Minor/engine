#include "components/colliders/polygoncollider.hpp"

PolygonCollider::PolygonCollider() : Collider(){}

PolygonCollider::PolygonCollider(std::vector<Vector2d> points) : Collider(){
    set_points(points);
}

std::vector<Vector2d> PolygonCollider::get_points(){
    return _points;
}

void PolygonCollider::set_points(std::vector<Vector2d> p){
    _points = p;
}
