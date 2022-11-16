#ifndef ENGINE_IRENDERER_HPP
#define ENGINE_IRENDERER_HPP

#include "itexture.hpp"

class Sprite;

class IRenderer {
public:
    virtual void render_sprite(const Sprite &sprite, ITexture &texture, bool is_world_space) const = 0;
};

#endif //ENGINE_IRENDERER_HPP
