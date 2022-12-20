#include <iostream>
#include "gameobject.hpp"

#include "components/text.hpp"

#include "global.hpp"
#include "sdltext.hpp"
#include "sdlrenderer.hpp"
#include "../rendercall.hpp"
#include "uiobject.hpp"

#include "fmt/core.h"


Text::Text(const std::string& text,
	const std::string& font_path,
	const int font_size,
	int order_in_layer,
	const Color& foreground_color,
	const Color& background_color,
    float fps,
	float pixels_to_meters,
	bool flip_x,
	bool flip_y
) :
	IRenderable(order_in_layer),
	pixels_to_meters(pixels_to_meters),
	_font_path(font_path),
	_font_size(font_size),
	_foreground_color(foreground_color),
	_background_color(background_color),
	flip_x(flip_x),
	flip_y(flip_y),
	_prev_text(text),
	_fps(fps),
    _time_since_last_render(0.f)
{
	load_texture(text);
}

void Text::render() {
    const auto renderer = Global::get_instance()->get_engine().get_renderer();

    const auto ui_object = dynamic_cast<UIObject*>(game_object);
    if(ui_object) {
        auto render_call = RenderCall(
                [this, renderer, texture = _texture, transform = game_object->transform, ui_object]() {
                    renderer->render_texture(*texture, game_object->transform, ui_object->get_width(), ui_object->get_height());
                }, _order_in_layer);
        renderer->add_render_call(render_call);
    }
    else {
        auto render_call = RenderCall(
                [this, renderer, texture = _texture, transform = game_object->transform]() {
                    renderer->render_texture(*texture, game_object->transform, pixels_to_meters);
                }, _order_in_layer);
        renderer->add_render_call(render_call);
    }
}

void Text::load_texture(const std::string& text)
{
	_texture = std::make_shared<SdlText>(text, _font_path, _font_size, _foreground_color, _background_color);
}

void Text::set_text(const std::string& text)
{
    if(_prev_text != text && should_render()) {
        _texture->render_texture(text);
        _prev_text = text;
    }
}

bool Text::should_render() {
    const auto delta_time = Global::get_instance()->get_delta_time();
    _time_since_last_render += delta_time;
    if (_time_since_last_render > (1000.f / _fps)) {
        _time_since_last_render = 0;
        return true;
    }
    return false;
}