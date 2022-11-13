//
// Created by lars on 13-11-22.
//

#ifndef ENGINE_IRENDERER_HPP
#define ENGINE_IRENDERER_HPP

#include "components/Sprite.hpp"
#include "ITexture.hpp"

class IRenderer {
public:
    virtual void renderSprite(Sprite &sprite, ITexture &texture, bool isWorldSpace = true) const = 0;
};

#endif //ENGINE_IRENDERER_HPP
