#include "render/itexture.hpp"
#include "uiobjects/text.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "sdlrenderer.hpp"
#include "utils/exceptionhandlers.hpp"

#include "SDL.h"
#include "SDL2pp/SDL.hh"
#include "SDL2pp/Renderer.hh"
#include "SDL2pp/Window.hh"
#include "SDL2pp/Color.hh"
#include "SDL2pp/SDLImage.hh"
#include "SDL2pp/Exception.hh"
#include "SDL2pp/SDL2pp.hh"
#include "fmt/ostream.h"

#include <ostream>



void SdlRenderer::render_sprite(const Sprite& sprite, ITexture& texture, bool is_world_space) const
{
	/** 
	 * TODO Task: Render sprite
	 * https://app.clickup.com/t/358vf6w
	 */

	//SDL2pp::Texture sprite2(*_renderer, texture);
}

void SdlRenderer::render_collider() const
{
	//TODO Params for this func undefined in API
	/**
	 * TODO Task: Debug draw for colliders (vertex renderer)
	 * https://app.clickup.com/t/34xa6tw
	 */
}

void SdlRenderer::render_text(Text& text) const
{
	/**
	 * TODO Task: Render text
	 * https://app.clickup.com/t/358vh7v
	 */
}

void SdlRenderer::clear(const Color& color) const try
{
	const auto _color = static_cast<SDL2pp::Color>(color);
	_renderer->SetDrawColor(_color).Clear();
}
catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlRenderer::push_to_screen() const try
{
	_renderer->Present();
}
catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlRenderer::init(int res_x, int res_y) try 
{
	SDL2pp::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL2pp::SDLImage sdl_image;

	_window = std::make_unique<SDL2pp::Window>("UnEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		res_x, res_y,
		SDL_WINDOW_RESIZABLE);

	_renderer = std::make_unique<SDL2pp::Renderer>(*_window, -1, SDL_RENDERER_ACCELERATED);
}
catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

std::shared_ptr<SDL2pp::Renderer> SdlRenderer::get_renderer()
{
	return _renderer;
}

SdlRenderer::SdlRenderer(int res_x, int res_y)
{
	init(res_x, res_y);
}

SdlRenderer::~SdlRenderer() = default;
