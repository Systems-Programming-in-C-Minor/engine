#pragma once

#include "uiobject.hpp"
#include "enums/alignment.hpp"
#include "color.hpp"


/**
 * @brief Class representing a piece of text which can be rendered.
*/
class Text : public UIObject  {
private:
    std::string _text;
    std::string _font;
    int _size;
    Alignment _alignment;
    Color _color;
    int _order_in_layer;
public:
    /**
     * @brief Constructor.
     * @param name The name of the text GameObject.
     * @param tag The tag of the text GameObject.
     * @param is_world_space Boolean option if the text will be rendered in world space.
     * @param transform The transform of the text.
     * @param width The width of the text.
     * @param height The height of the text.
     * @param text The actual text which will be shown.
     * @param font The font of the text.
     * @param size The size of the text.
     * @param alignment The alignment enum of the text.
     * @param color The color of the text.
     * @param order_in_layer The order in which the text will be rendered.
     */
    Text(const std::string& name, const std::string& tag, bool is_world_space, Transform transform, int width, int height,
        std::string  text, std::string  font, int size, Alignment alignment, Color color, int order_in_layer);
    [[nodiscard]] std::string get_text() const;
    [[nodiscard]] std::string get_font() const;
    [[nodiscard]] int get_size() const;
    [[nodiscard]] Alignment get_alignment() const;
    [[nodiscard]] Color get_color() const;
    void set_text(std::string new_text);
    void set_font(std::string new_font);
    void set_size(int new_size);
    void set_alignment(Alignment new_alignment);
    void set_color(Color new_color);
    void render() const override;
};
