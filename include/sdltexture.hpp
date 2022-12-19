#ifndef ENGINE_SDLTEXTURE_H_rv0FzK8Lx6
#define ENGINE_SDLTEXTURE_H_rv0FzK8Lx6

#include "render/itexture.hpp"

#include <memory>

namespace SDL2pp {
	class Texture;
}

class SdlRenderer;

class SdlTexture : public ITexture
{
public:
	/**
	 * @brief A texture used by SDL
	 * @param path (Relative) path to a texture
	 */
	SdlTexture(const std::string& path);

	/**
	 * @brief A texture used by SDL
	 * @param path path (Relative) path to a texture
	 * @param[out] res_x X-axis resolution of the texture
	 * @param[out] res_y Y-axis resolution of the texture
	 */
	SdlTexture(const std::string& path, unsigned int* res_x, unsigned int* res_y);

	[[nodiscard]] std::shared_ptr<SDL2pp::Texture> get_texture() const override;
	void set_color(const Color& color) override;
private:
	std::shared_ptr<SDL2pp::Texture> _texture;

	void load_texture(const std::string& path);
	void get_resolution(unsigned int* res_x, unsigned int* res_y) const;
};

#endif // ENGINE_SDLTEXTURE_H_rv0FzK8Lx6