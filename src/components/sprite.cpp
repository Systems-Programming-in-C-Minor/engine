#include "gameobject.hpp"

#include "components/sprite.hpp"

#include "global.hpp"
#include "sdltexture.hpp"
#include "sdlrenderer.hpp"
#include "../rendercall.hpp"


Sprite::Sprite(std::string sprite, Color color, bool flip_x, bool flip_y, int sorting_layer, int order_in_layer, float pixels_to_meters) :
		IRenderable(order_in_layer),
		res_x(0),
		res_y(0),
		pixels_to_meters(pixels_to_meters),
		_sprite(std::move(sprite)),
		color(color),
		flip_x(flip_x),
		flip_y(flip_y),
		sorting_layer(sorting_layer),
		order_in_layer(order_in_layer)
{
	load_texture();
}

void Sprite::render(bool is_world_space) const {
	const auto renderer = Global::get_instance()->get_engine().get_renderer();
    auto render_call = RenderCall([this, renderer, texture = _texture, transform = game_object->transform, is_world_space](){
        renderer->render_sprite(*this, *texture, game_object->transform, is_world_space);
        }, _order_in_layer);
	renderer->add_render_call(render_call);
}

float Sprite::get_size_x() const
{
	return static_cast<float>(res_x) / pixels_to_meters;
}
float Sprite::get_size_y() const
{
	return static_cast<float>(res_y) / pixels_to_meters;
}

void Sprite::load_texture()
{
	_texture = std::make_shared<SdlTexture>(_sprite, &res_x, &res_y);
}
