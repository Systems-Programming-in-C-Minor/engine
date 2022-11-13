//
// Created by lars on 13-11-22.
//

#ifndef ENGINE_IRENDERER_HPP
#define ENGINE_IRENDERER_HPP

#include "ITexture.hpp"

class Sprite;

class IRenderer {
public:
    virtual void renderSprite(const Sprite &sprite, ITexture &texture, bool isWorldSpace) = 0;
};

#endif //ENGINE_IRENDERER_HPP
