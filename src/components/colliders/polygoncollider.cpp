#include "components/colliders/polygoncollider.hpp"

PolygonCollider::PolygonCollider(std::vector<Vector2d> points) : Collider(){
    _points = std::move(points);
}

PolygonCollider::PolygonCollider(std::string path): Collider() {
    _points = construct_points(std::move(path));
}

std::vector<Vector2d> PolygonCollider::get_points() const {
    return _points;
}

std::vector<Vector2d> PolygonCollider::construct_points(std::string path) {
    std::vector<Vector2d> vec;
    return vec;

}
