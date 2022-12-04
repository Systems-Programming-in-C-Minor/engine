#include "transform.hpp"
#include "render/itexture.hpp"
#include "uiobjects/text.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "sdlrenderer.hpp"
#include "utils/exceptionhandlers.hpp"
#include "vector2d.hpp"
#include "utils/trigonometry.hpp"

#include "SDL.h"
#include "SDL2pp/SDL.hh"
#include "SDL2pp/Renderer.hh"
#include "SDL2pp/Window.hh"
#include "SDL2pp/Color.hh"
#include "SDL2pp/SDLImage.hh"
#include "SDL2pp/Exception.hh"
#include "SDL2pp/Point.hh"
#include "fmt/ostream.h"

#include <cmath>
#include <ostream>



void SdlRenderer::render_sprite(const Sprite& sprite, ITexture& texture, Transform& transform, bool is_world_space) const
{
	/*
	 * TODO Open PR for SDL2pp
	 * Segfaults, SDL2pp needs to fix this
	 * int x = _renderer->GetOutputWidth();
	 * int x, y = 0;
	 * SDL_GetRendererOutputSize(_renderer->Get(), &x, nullptr);
	 */

	const double left_corner_x = -(transform.get_position().x + sprite.get_size_x() * transform.get_scale() / 2.0);
	const double left_corner_y = transform.get_position().y + sprite.get_size_y() * transform.get_scale() / 2.0;

	const auto center = world_to_screen(transform.get_position());
	const auto left_corner = world_to_screen(Vector2d{ left_corner_x, left_corner_y });

	const int size_x = static_cast<int>(round(sprite.get_size_x() * transform.get_scale() * _mtp));
	const int size_y = static_cast<int>(round(sprite.get_size_y() * transform.get_scale() * _mtp));
	const auto size = SDL2pp::Point{ size_x, size_y };

	auto rect = SDL2pp::Rect{ left_corner, size };
	_renderer->Copy(*texture.get_texture(), SDL2pp::NullOpt, rect, radians_to_degrees(transform.get_angle()));
}

void SdlRenderer::render_collider() const
{
	// TODO Params for this func undefined in API
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
	// TODO Preferably implement cast from Color to SDL2pp::Color/SDL_Color
	constexpr SDL2pp::Color _color = { 0, 0, 0, 255 };
	_renderer->SetDrawColor(_color).Clear();
} catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlRenderer::push_to_screen() const try
{
	_renderer->Present();
} catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlRenderer::init(int res_x, int res_y) try 
{
	_sdl = std::make_unique<SDL2pp::SDL>(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	_sdl_image = std::make_unique<SDL2pp::SDLImage>();

	_window = std::make_shared<SDL2pp::Window>("UnEngine",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		res_x, res_y,
		SDL_WINDOW_RESIZABLE);

	_renderer = std::make_shared<SDL2pp::Renderer>(*_window, -1, SDL_RENDERER_ACCELERATED);
} catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

SDL2pp::Point SdlRenderer::world_to_screen(const Vector2d& position) const
{
	// TODO Optimization: only retrieve when resolution changes
	SDL2pp::Point res = _renderer->GetOutputSize();
	const SDL2pp::Point return_pos{
		static_cast<int>(round(res.GetX() * 0.5 + position.x * _mtp)),
		static_cast<int>(round(res.GetY() * 0.5 - position.y * _mtp))
	};
	return return_pos;
}

std::shared_ptr<SDL2pp::Renderer> SdlRenderer::get_renderer()
{
	return _renderer;
}

SdlRenderer::SdlRenderer(int res_x, int res_y)
{
	init(res_x, res_y);
}

SdlRenderer::~SdlRenderer() = default;
