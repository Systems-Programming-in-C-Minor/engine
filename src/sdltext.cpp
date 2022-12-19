#include "sdlrenderer.hpp"
#include "color.hpp"
#include "utils/exceptionhandlers.hpp"
#include "global.hpp"

#include "SDL2pp/Texture.hh"
#include "SDL2pp/Font.hh"

#include "sdltext.hpp"

#include <string>
#include <filesystem>

SdlText::SdlText(const std::string& text,
	const std::string& font_path,
	const int font_size,
	const Color& foreground_color,
	const Color& background_color) :
	_font_path(font_path),
	_font_size(font_size),
	_foreground_color(foreground_color),
	_background_color(background_color)
{
	cache_font();
	render_texture(text);
};

SdlText::~SdlText() = default;

void SdlText::set_color(const Color & color)
{
	_texture->SetColorAndAlphaMod(static_cast<SDL2pp::Color>(color));
}

std::shared_ptr<SDL2pp::Texture> SdlText::get_texture() const
{
	return _texture;
}

float SdlText::get_size_x() const
{
	return static_cast<float>(_texture->GetWidth());
}

float SdlText::get_size_y() const
{
	return static_cast<float>(_texture->GetHeight());
}

void SdlText::cache_font()
{
	_font = std::make_unique<SDL2pp::Font>(_font_path, _font_size);
}


void SdlText::render_texture(const std::string& text)
try {
	const std::shared_ptr<IRenderer> renderer = Global::get_instance()->get_engine().get_renderer();
	const std::shared_ptr<SDL2pp::Renderer> sdl_renderer = std::dynamic_pointer_cast<SdlRenderer>(renderer)->get_renderer();

	_texture = std::make_shared<SDL2pp::Texture>( *sdl_renderer, _font->RenderText_Shaded(
		text,
		static_cast<SDL2pp::Color>(_foreground_color),
		static_cast<SDL2pp::Color>(_background_color)
	));
}
catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

