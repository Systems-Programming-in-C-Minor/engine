#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include "interfaces/irenderable.hpp"
#include "string"
#include "component.hpp"
#include "color.hpp"
#include "render/itexture.hpp"
#include "memory"

/**
 * @brief A component representing a sprite (small image)
 */
class Sprite : public Component, public IRenderable {
public:
    /**
     * @brief The pixels to meters ratio of the Sprite.
     */
    float pixels_to_meters;

    /**
     * @brief Constructor
     * @param sprite The path to the sprite image.
     * @param order_in_layer The order in which the sprite will be rendered.
     * @param pixels_to_meters The pixels to meters scale.
     * @param color The initial color of the sprite.
     * @param flip_x The flip x value of the sprite.
     * @param flip_y The flip y value of the sprite.
     */
    Sprite(std::string sprite, int order_in_layer, float pixels_to_meters = 100.f, Color color = Color{0, 0, 0, 0}, bool flip_x = false, bool flip_y = false);

    /**
     * @brief Render the sprite.
     */
    void render() override;

    /**
     * @brief Setter for the color of the sprite.
     * @param color The new color of the sprite.
     */
    void set_color(const Color& color);
private:
    Color color;
    bool flip_x;
    bool flip_y;
    std::shared_ptr<ITexture> _texture;

    /**
     * @brief Load the texture of the sprite.
     * @param sprite The path to the sprite image.
     */
    void load_texture(const std::string& sprite);
};

#endif //ENGINE_SPRITE_HPP
