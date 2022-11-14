#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include "renderer/IRenderable.hpp"
#include "string"
#include "Component.hpp"
#include "Color.hpp"
#include "renderer/ITexture.hpp"
#include "memory"

using namespace std;

class Sprite : public Component, public IRenderable {
public:
    Sprite(string sprite, Color color, bool flip_x, bool flip_y, int sorting_layer, int order_in_layer);

    void render(IRenderer &renderer, bool is_world_space = true) const override;

private:
    std::string sprite;
    Color color;
    bool flip_x;
    bool flip_y;
    int sorting_layer;
    int order_in_layer;

    unique_ptr<ITexture> texture;
};

#endif //ENGINE_SPRITE_HPP
