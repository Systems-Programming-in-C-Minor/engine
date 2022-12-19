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
     * @brief Constructor.
     * @param path The path to the texture.
     */
    ITexture(const std::string& path) {}

    virtual void set_color(const Color& color) = 0;
private:
    friend class SdlRenderer;
    /**
     * @brief Getter for the texture.
     *        Override for implementing the desired behaviour.
     * @return a shared pointer containing a Texture object.
     */
    [[nodiscard]] virtual std::shared_ptr<SDL2pp::Texture> get_texture() const = 0;
};


#endif //ENGINE_ITEXTURE_HPP
