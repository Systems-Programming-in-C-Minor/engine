#ifndef ENGINE_ITEXTURE_HPP
#define ENGINE_ITEXTURE_HPP

#include <string>   

class IRenderer;

class ITexture {
public:
    ITexture(const std::string& path, IRenderer& renderer) {}
};

#endif //ENGINE_ITEXTURE_HPP
