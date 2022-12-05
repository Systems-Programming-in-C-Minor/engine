#ifndef ENGINE_ITEXTURE_HPP
#define ENGINE_ITEXTURE_HPP

#include <string>
#include <memory>

class IRenderer;

namespace SDL2pp {
    class Texture;
}

class ITexture {
public:
    // TODO Possibly remove renderer param in favour of renderer in global singleton
    ITexture(const std::string& path) {}

    [[nodiscard]] virtual std::shared_ptr<SDL2pp::Texture> get_texture() const = 0;
};


#endif //ENGINE_ITEXTURE_HPP
