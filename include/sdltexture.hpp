#ifndef ENGINE_SDLTEXTURE_H_rv0FzK8Lx6
#define ENGINE_SDLTEXTURE_H_rv0FzK8Lx6

#include "render/itexture.hpp"

#include <memory>

namespace SDL2pp {
	class Texture;
}

/**
 * @brief SDL texture implementation of the ITexture interface.
 */
class SdlTexture : public ITexture
{
public:
	/**
	 * @brief Constructor.
	 * @param path (Relative) path to a texture
	 */
	SdlTexture(const std::string& path);

    /**
     * @brief Setter method for the color
     * @param color The Color object which will be set.
     */
    void set_color(const Color& color) override;
private:
	std::shared_ptr<SDL2pp::Texture> _texture;

    /**
     * @brief Load method for the texture.
     * @param path The path from which the texture will be loaded.
     */
    void load_texture(const std::string& path);

    /**
     * @brief Getter method for the texture.
     * @return A shared pointer to an SDL2pp::Texture object.
     */
	[[nodiscard]] std::shared_ptr<SDL2pp::Texture> get_texture() const override;

    /**
     * @brief Getter method for the x size.
     * @return A float value of the x size.
     */
    [[nodiscard]] float get_size_x() const override;

    /**
     * @brief Getter method for the y size.
     * @return A float value of the y size.
     */
	[[nodiscard]] float get_size_y() const override;
};

#endif // ENGINE_SDLTEXTURE_H_rv0FzK8Lx6