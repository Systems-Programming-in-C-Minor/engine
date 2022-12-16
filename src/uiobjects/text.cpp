#include <utility>

#include "uiobjects/text.hpp"
#include "uiobject.hpp"
#include "global.hpp"
#include "../rendercall.hpp"

Text::Text(const std::string& name,
    const std::string& tag,
    bool is_world_space,
    Transform transform,
    int width, int height,
    std::string text,
    std::string font,
    int size,
    Alignment alignment,
    int order_in_layer,
    Color foreground_color,
    Color background_color,
    Space space
    ) :
	UIObject(name, tag, is_world_space, transform, width, height, space),
	_text(std::move(text)),
	_font(std::move(font)),
	_size(size),
	_alignment(alignment),
	_fg_color(foreground_color),
	_bg_color(background_color),
	_order_in_layer(order_in_layer)
{
}

Text::~Text() = default;

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

Color Text::get_fg_color() const {
    return _fg_color;
}

Color Text::get_bg_color() const {
    return _bg_color;
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

void Text::set_fg_color(const Color& new_color) {
    _fg_color = new_color;
}

void Text::set_bg_color(const Color& new_color)
{
    _bg_color = new_color;
}

void Text::render() const {
    const auto renderer = Global::get_instance()->get_engine().get_renderer();
    auto render_call = RenderCall([this, renderer]() {
        renderer->render_text(*this);
        }, _order_in_layer);
    renderer->add_render_call(render_call);
}
