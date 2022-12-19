#ifndef ENGINE_ITEXTURE_HPP
#define ENGINE_ITEXTURE_HPP

#include <string>
#include <memory>

class SdlRenderer;

namespace SDL2pp {
    class Texture;
}

class ITexture {
private:
    friend class SdlRenderer;
protected:
    [[nodiscard]] virtual std::shared_ptr<SDL2pp::Texture> get_texture() const = 0;
    [[nodiscard]] virtual float get_size_x() const = 0;
    [[nodiscard]] virtual float get_size_y() const = 0;
};


#endif //ENGINE_ITEXTURE_HPP
