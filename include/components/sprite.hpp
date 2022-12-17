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
    unsigned int res_x, res_y;
    float pixels_to_meters;

    Sprite(std::string sprite, Color color, bool flip_x, bool flip_y, int sorting_layer, int order_in_layer, float pixels_to_meters = 100.f);

    void render(bool is_world_space) const override;
    [[nodiscard]] float get_size_x() const;
    [[nodiscard]] float get_size_y() const;
    void set_color(const Color& color);
private:
    std::string _sprite;
    Color color;
    bool flip_x;
    bool flip_y;
    int sorting_layer;
    int order_in_layer;
    std::shared_ptr<ITexture> _texture;

    void load_texture();
};

#endif //ENGINE_SPRITE_HPP
