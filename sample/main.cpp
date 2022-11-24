#include "sdlrenderer.hpp"
#include "color.hpp"
#include "sdltexture.hpp"

int main(int argc, char* argv[])
{
	auto renderer = SdlRenderer(800, 600);
	SdlTexture texture{ renderer,"./assets/sample.png" };
	renderer.clear(Color(0.0, 0.0, 0.0, 255.0));
	renderer.push_to_screen();
}
