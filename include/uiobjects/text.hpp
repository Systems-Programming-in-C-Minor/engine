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
    Color _fg_color;
    Color _bg_color;
    int _order_in_layer;
public:
    Text(const std::string& name,
        const std::string& tag,
        bool is_world_space,
        Transform transform,
        int width,
        int height,
        std::string text,
        std::string font,
        int size, 
        Alignment alignment, 
        int order_in_layer,
        Color foreground_color,
        Color background_color = Color{0, 0, 0, 255},
        Space space = Space::SCREEN
    );
    virtual ~Text() override;
    [[nodiscard]] std::string get_text() const;
    [[nodiscard]] std::string get_font() const;
    [[nodiscard]] int get_size() const;
    [[nodiscard]] Alignment get_alignment() const;
    [[nodiscard]] Color get_fg_color() const;
    [[nodiscard]] Color get_bg_color() const;
    void set_text(std::string new_text);
    void set_font(std::string new_font);
    void set_size(int new_size);
    void set_alignment(Alignment new_alignment);
    void set_fg_color(const Color& new_color);
    void set_bg_color(const Color& new_color);
    void render() const override;
};
