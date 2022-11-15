#ifndef SDL_RENDERER_H_Hbcayj12iU
#define SDL_RENDERER_H_Hbcayj12iU

#include <memory>

namespace SDL2pp 
{
	class Window;
	class Renderer;
}

class SdlRenderer {
public:
	SdlRenderer();
	~SdlRenderer();;
private:
	void init();

	std::unique_ptr<SDL2pp::Window> _window;
	std::unique_ptr<SDL2pp::Renderer> _renderer;
};

#endif // SDL_RENDERER_H_Hbcayj12iU