#include "gameobject.hpp"

#include "components/sprite.hpp"

#include "global.hpp"
#include "sdltexture.hpp"
#include "sdlrenderer.hpp"
#include "uiobject.hpp"
#include "../rendercall.hpp"


Sprite::Sprite(std::string sprite, int order_in_layer, float pixels_to_meters, Color color, bool flip_x, bool flip_y) :
		IRenderable(order_in_layer),
		res_x(0),
		res_y(0),
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

float Sprite::get_size_x() const
{
	return static_cast<float>(res_x) / pixels_to_meters;
}
float Sprite::get_size_y() const
{
	return static_cast<float>(res_y) / pixels_to_meters;
}

void Sprite::load_texture(const std::string& sprite)
{
	_texture = std::make_shared<SdlTexture>(sprite, &res_x, &res_y);
}

void Sprite::set_color(const Color& color) {
	_texture->set_color(color);
}
