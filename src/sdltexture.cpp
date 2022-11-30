#include "sdlrenderer.hpp"
#include "sdltexture.hpp"
#include "utils/exceptionhandlers.hpp"

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

std::shared_ptr<SDL2pp::Texture> SdlTexture::get_texture() const
{
	return _texture;
}

void SdlTexture::load_texture(const std::string& path, SdlRenderer& renderer)
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
