#ifndef ENGINE_ITEXTURE_HPP
#define ENGINE_ITEXTURE_HPP

#include <string>
#include <memory>

class SdlRenderer;

namespace SDL2pp {
    class Texture;
}

/**
 * @brief Interface for all textures.
 */
class ITexture {
public:
    /**
     * @brief Method which sets the color of the texture.
     *        Override for implementing the desired behaviour.
     * @param color The color which will be set.
     */
    virtual void set_color(const Color& color) = 0;
private:
    friend class SdlRenderer;
protected:
    /**
     * @brief Getter method for the texture.
     *        Override for implementing the desired behaviour.
     * @return A Shared Pointer of a SDL2pp::Texture.
     */
    [[nodiscard]] virtual std::shared_ptr<SDL2pp::Texture> get_texture() const = 0;

    /**
     * @brief Getter method for the size x.
     *        Override for implementing the desired behaviour.
     * @return An integer value containing size x.
     */
    [[nodiscard]] virtual float get_size_x() const = 0;

    /**
     * @brief Getter method for the size y.
     *        Override for implementing the desired behaviour.
     * @return An integer value containing size y.
     */
    [[nodiscard]] virtual float get_size_y() const = 0;
};


#endif //ENGINE_ITEXTURE_HPP
