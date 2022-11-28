#include "sdlrenderer.hpp"
#include "sdltexture.hpp"
#include "utils/exceptionhandlers.hpp"

#include "SDL2pp/Texture.hh"
#include "fmt/core.h"

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

/**
 * @brief A texture used by SDL
 * @param renderer Reference to an active SdlRenderer instance
 * @param path (Relative) path to a texture
 */
SdlTexture::SdlTexture(SdlRenderer& renderer, const std::string& path) :
	ITexture(path, renderer)
{
	load_texture(path, renderer);
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

	_texture = std::make_shared<SDL2pp::Texture>(SDL2pp::Texture(*renderer.get_renderer(), texture.string()));
}
catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }
