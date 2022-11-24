#ifndef ENGINE_SDLTEXTURE_H_rv0FzK8Lx6
#define ENGINE_SDLTEXTURE_H_rv0FzK8Lx6

#include "render/itexture.hpp"

#include <memory>

namespace SDL2pp {
	class Texture;
}

class SdlRenderer;

class SdlTexture : ITexture
{
public:
	SdlTexture(SdlRenderer& renderer, const std::string& path);

private:
	std::shared_ptr<SDL2pp::Texture> _texture;

	void load_texture(const std::string& path, SdlRenderer& renderer);
};

#endif // ENGINE_SDLTEXTURE_H_rv0FzK8Lx6