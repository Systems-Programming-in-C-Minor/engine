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
    unsigned int res_x, res_y;
    float pixels_to_meters;

    Sprite(std::string sprite, int order_in_layer, float pixels_to_meters = 100.f, Color color = Color{0, 0, 0, 0}, bool flip_x = false, bool flip_y = false);

    /**
     * @brief Render the sprite.
     * @param is_world_space Optionally render the sprite in world space.
     */
    void render(bool is_world_space) override;

    /**
     * @brief Getter for the current size x.
     * @return The current size x.
     */
    [[nodiscard]] float get_size_x() const;

    /**
     * @brief Getter for the current size y.
     * @return The current size y.
     */
    [[nodiscard]] float get_size_y() const;
    void set_color(const Color& color);
private:
    Color color;
    bool flip_x;
    bool flip_y;
    std::shared_ptr<ITexture> _texture;

    void load_texture(const std::string& sprite);
};

#endif //ENGINE_SPRITE_HPP
