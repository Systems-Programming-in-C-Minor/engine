#include "components/colliders/polygoncollider.hpp"

PolygonCollider::PolygonCollider(std::vector<Vector2d> points) : Collider(){
    _points = std::move(points);
}

PolygonCollider::PolygonCollider(const std::string& path): Collider() {
    construct_points(path);
}

std::vector<Vector2d> PolygonCollider::get_points() const {
    return _points;
}

void PolygonCollider::construct_points(const std::string& path) {
    /*
     * TODO Task: Implement SpriteCollider
     * https://app.clickup.com/t/377pt9y
     */
    _points = std::vector<Vector2d>{Vector2d{}};
}
