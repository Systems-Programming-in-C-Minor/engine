#include "components/Sprite.hpp"

Sprite::Sprite(std::string sprite, Color color, bool flip_x, bool flip_y, int sorting_layer, int order_in_layer) :
        sprite(std::move(sprite)),
        color(color),
        flip_x(flip_x),
        flip_y(flip_y),
        sorting_layer(sorting_layer),
        order_in_layer(order_in_layer) {}

void Sprite::render(IRenderer &renderer, bool is_world_space) const {
    renderer.render_sprite(*this, *texture, is_world_space);
}
