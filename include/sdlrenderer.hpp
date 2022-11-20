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
	SdlRenderer(int res_x, int res_y);
	~SdlRenderer();
private:
	void init(int rex_x = 800, int res_y = 600);

	std::unique_ptr<SDL2pp::Window> _window;
	std::unique_ptr<SDL2pp::Renderer> _renderer;
};

#endif // SDL_RENDERER_H_Hbcayj12iU