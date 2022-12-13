#include <utility>

#include "uiobjects/text.hpp"
#include "uiobject.hpp"
#include "global.hpp"

Text::Text(const std::string& name, const std::string& tag, int width, int height, std::string text, std::string font, int size, Alignment alignment, Color color) : UIObject(name, tag, width, height),
    _text(std::move(text)),
    _font(std::move(font)),
    _size(size),
    _alignment(alignment),
    _color(color)
{
}

std::string Text::get_text() const {
    return _text;
}

std::string Text::get_font() const {
    return _font;
}

int Text::get_size() const {
    return _size;
}

Alignment Text::get_alignment() const {
    return _alignment;
}

Color Text::get_color() const {
    return _color;
}

void Text::set_text(std::string new_text) {
    _text = std::move(new_text);
}

void Text::set_font(std::string new_font) {
    _font = std::move(new_font);
}

void Text::set_size(int new_size) {
    _size = new_size;
}

void Text::set_alignment(Alignment new_alignment) {
    _alignment = new_alignment;
}

void Text::set_color(Color new_color) {
    _color = new_color;
}

void Text::render() const {
    const auto renderer = Global::get_instance()->get_engine().get_renderer();
    renderer->render_text(*this);
}
