#include <utility>

#include "uiobjects/text.hpp"
#include "uiobject.hpp"

Text::Text(const std::string& name, const std::string& tag, double width, double height, const std::string& text, const std::string& font, int size, Alignment alignment) : UIObject(name, tag, width, height),
    _text(text),
    _font(font),
    _size(size),
    _alignment(alignment)
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
