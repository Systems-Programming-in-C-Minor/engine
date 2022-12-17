#ifndef ENGINE_ITEXTURE_HPP
#define ENGINE_ITEXTURE_HPP

#include <string>
#include <memory>

class SdlRenderer;

namespace SDL2pp {
    class Texture;
}

class ITexture {
public:
    ITexture(const std::string& path) {}

    virtual void set_color(const Color& color) = 0;
private:
    friend class SdlRenderer;
    [[nodiscard]] virtual std::shared_ptr<SDL2pp::Texture> get_texture() const = 0;
};


#endif //ENGINE_ITEXTURE_HPP
