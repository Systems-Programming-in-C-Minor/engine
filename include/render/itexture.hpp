#ifndef ENGINE_ITEXTURE_HPP
#define ENGINE_ITEXTURE_HPP

#include <string>   

class IRenderer;

class ITexture {
public:
    // TODO Possibly remove renderer param in favour of renderer in global singleton
    ITexture(const std::string& path, IRenderer& renderer) {}
};

#endif //ENGINE_ITEXTURE_HPP
