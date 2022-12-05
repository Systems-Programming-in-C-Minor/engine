#include "sdlrenderer.hpp"
#include "sdltexture.hpp"
#include "utils/exceptionhandlers.hpp"
#include "global.hpp"

#include "SDL2pp/Texture.hh"
#include "fmt/core.h"

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

SdlTexture::SdlTexture(const std::string& path) :
	ITexture(path)
{
	load_texture(path);
}

SdlTexture::SdlTexture(const std::string& path, unsigned int* res_x, unsigned int* res_y) :
	ITexture(path)
{
	load_texture(path);
	if (_texture) {
		get_resolution(res_x, res_y);
	}
}

std::shared_ptr<SDL2pp::Texture> SdlTexture::get_texture() const
{
	return _texture;
}

void SdlTexture::load_texture(const std::string& path)
try {
	const fs::path texture = fs::current_path().append(path);

	if (!is_regular_file(texture)) {
		fmt::print("File {} not found\n", texture.string());
		return;
	}

	if (texture.extension() != ".png") {
		fmt::print("Unsupported texture format {}\n", texture.extension().string());
		return;
	}

	auto renderer = Global::get_instance()->get_engine().get_renderer();
	auto sdl_renderer = std::dynamic_pointer_cast<SdlRenderer>(renderer);
	if (sdl_renderer) {
		_texture = std::make_shared<SDL2pp::Texture>(SDL2pp::Texture(*sdl_renderer->get_renderer(), texture.string()));
	} else {
		fmt::print(std::cerr, "SDL Renderer could not be found, texture not loaded");
	}
}
catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlTexture::get_resolution(unsigned int * res_x, unsigned int * res_y) const
try {
	*res_x = _texture->GetWidth();
	*res_y = _texture->GetHeight();
}
catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

