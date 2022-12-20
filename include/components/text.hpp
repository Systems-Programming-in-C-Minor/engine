#ifndef ENGINE_TEXT_HPP
#define ENGINE_TEXT_HPP

#include "interfaces/irenderable.hpp"
#include "component.hpp"
#include "color.hpp"

#include <string>
#include <memory>

/**
 * @brief Class representing a piece of text which can be rendered.
 */
class Text : public Component, public IRenderable {
public:
    float pixels_to_meters;

    /**
     * @brief Constructor.
     * @param text The actual text which will be shown.
     * @param font_path The path to the font of the text.
     * @param font_size The size of the text.
     * @param order_in_layer The order in which the text will be rendered.
     * @param foreground_color The color of the foreground of the text.
     * @param background_color_color The color of the background od the text.
     * @param fps Initial fps value.
     * @param pixels_to_meters The pixels to meters ratio.
     * @param flip_x The flip x value of the sprite.
     * @param flip_y The flip y value of the sprite.
     */
    Text(const std::string& text,
        const std::string& font_path,
        const int font_size,
        int order_in_layer,
        const Color& foreground_color = Color{ 255, 255, 255, 0 },
        const Color& background_color = Color{ 0, 0, 0, 255 },
        float fps = 30.f,
        float pixels_to_meters = 100.f,
        bool flip_x = false,
        bool flip_y = false
    );

    /**
     * @brief Render the text.
     */
    void render() override;

    /**
     * @brief Set the text string.
     * @param Set the string which will be set.
     */
    void set_text(const std::string& text);
private:
    std::string _font_path;
    int _font_size;
    Color _foreground_color;
    Color _background_color;
    bool flip_x;
    bool flip_y;
    std::string _prev_text;
    float _fps;
    float _time_since_last_render;
    std::shared_ptr<SdlText> _texture;

    /**
     * @brief Load the texture of the Text.
     * @param text The text which will be loaded.
     */
    void load_texture(const std::string& text);

    /**
     * @brief Return whether or not the text should be rendered.
     * @return A boolean value if the text should be rendered or not.
     */
    bool should_render();
};

#endif //ENGINE_TEXT_HPP
