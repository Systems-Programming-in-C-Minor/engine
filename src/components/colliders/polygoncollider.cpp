#include "components/colliders/polygoncollider.hpp"
#include "box2d/b2_chain_shape.h"

PolygonCollider::PolygonCollider(std::vector<Vector2d> points, ColliderNormal collider_normal) : Collider(){
    _points = std::move(points);
    set_shape(collider_normal);
}

PolygonCollider::PolygonCollider(const std::string& path, ColliderNormal collider_normal): Collider() {
    get_points_from_file(path);
}

std::vector<Vector2d> PolygonCollider::get_points() const {
    return _points;
}

void PolygonCollider::get_points_from_file(const std::string& path) {
    /*
     * TODO Task: Implement SpriteCollider
     * https://app.clickup.com/t/377pt9y
     */
    _points = std::vector<Vector2d>{Vector2d{}};
}

void PolygonCollider::set_shape(ColliderNormal collider_normal) {
    std::vector<b2Vec2> vectors;

    if (collider_normal == ColliderNormal::outwards) {
        for (auto i = _points.rbegin(); i != _points.rend(); ++i) {
            vectors.push_back(static_cast<b2Vec2>(*i));
        }
    }

    else if (collider_normal == ColliderNormal::inwards) {
        for (auto& vector2d : _points) {
            vectors.push_back(static_cast<b2Vec2>(vector2d));
        }
    }
    
    b2ChainShape chain;
    chain.CreateLoop(vectors.data(), static_cast<int>(vectors.size()));
    _shape = std::make_shared<b2ChainShape>(chain);
}
