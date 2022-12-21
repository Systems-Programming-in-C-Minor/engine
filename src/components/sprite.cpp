#include "gameobject.hpp"

#include "components/sprite.hpp"

#include "global.hpp"
#include "sdltexture.hpp"
#include "sdlrenderer.hpp"
#include "uiobject.hpp"
#include "../rendercall.hpp"
#include "render/texture_pool.hpp"


Sprite::Sprite(std::string sprite, int order_in_layer, float pixels_to_meters, Color color, bool flip_x, bool flip_y) :
		IRenderable(order_in_layer),
		pixels_to_meters(pixels_to_meters),
		color(color),
		flip_x(flip_x),
		flip_y(flip_y)
{
	load_texture(sprite);
}

void Sprite::render() {
    const auto renderer = Global::get_instance()->get_engine().get_renderer();

    const auto ui_object = dynamic_cast<UIObject*>(game_object);
    if (ui_object) {
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

void Sprite::load_texture(const std::string& sprite)
{
    _texture = Global::get_instance()->get_engine().get_renderer()->get_texture_pool()->load_texture(sprite);
}

void Sprite::set_color(const Color& color) {
	_texture->set_color(color);
}
