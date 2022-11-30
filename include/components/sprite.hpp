#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include "interfaces/irenderable.hpp"
#include "string"
#include "component.hpp"
#include "color.hpp"
#include "render/itexture.hpp"
#include "memory"

class Sprite : public Component, public IRenderable {
public:
    Sprite(std::string sprite, Color color, bool flip_x, bool flip_y, int sorting_layer, int order_in_layer);


    void render(bool is_world_space) const override;
private:
    std::string sprite;
    Color color;
    bool flip_x;
    bool flip_y;
    int sorting_layer;
    int order_in_layer;

    std::unique_ptr<ITexture> texture;
};

#endif //ENGINE_SPRITE_HPP
