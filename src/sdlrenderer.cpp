#include "SDL2pp/SDL2pp.hh"
#include "SDL.h"
#include "fmt/core.h"

#include "sdlrenderer.hpp"


void SdlRenderer::init() try 
{
	SDL2pp::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	_window = std::make_unique<SDL2pp::Window>("UnEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_RESIZABLE);

	_renderer = std::make_unique<SDL2pp::Renderer>(*_window, -1, SDL_RENDERER_ACCELERATED);
} catch (SDL2pp::Exception& e) {
	// Exception stores SDL_GetError() result and name of function which failed
	fmt::print("SDL error in: {}\n", e.GetSDLFunction());
	fmt::print("SDL error: {}\n", e.GetSDLError());
}

SdlRenderer::SdlRenderer()
{
	init();
}

SdlRenderer::~SdlRenderer() = default;
