#include "sdlrenderer.hpp"
#include "color.hpp"

int main(int argc, char* argv[])
{
	const auto renderer = SdlRenderer(800, 600);
	renderer.clear(Color(0.0, 0.0, 0.0, 255.0));
	renderer.push_to_screen();
}
