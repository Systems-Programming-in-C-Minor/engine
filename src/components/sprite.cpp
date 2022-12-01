#include "gameobject.hpp"

#include "components/sprite.hpp"

#include "global.hpp"
#include "sdltexture.hpp"
#include "sdlrenderer.hpp"


Sprite::Sprite(std::string sprite, Color color, bool flip_x, bool flip_y, int sorting_layer, int order_in_layer) :
		_sprite(std::move(sprite)),
		color(color),
		flip_x(flip_x),
		flip_y(flip_y),
		sorting_layer(sorting_layer),
		order_in_layer(order_in_layer),
		_res_x(0),
		_res_y(0)
{
	load_texture();
}

void Sprite::render(bool is_world_space) const {
	const auto renderer = Global::get_instance()->get_engine().get_renderer();
	renderer->render_sprite(*this, *_texture, game_object->transform, is_world_space);
}

void Sprite::load_texture()
{
	_texture = std::make_shared<SdlTexture>(_sprite, &_res_x, &_res_y);
}
