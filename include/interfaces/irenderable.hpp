#ifndef ENGINE_IRENDERABLE_HPP
#define ENGINE_IRENDERABLE_HPP

#include "render/irenderer.hpp"

class IRenderable {
public:
    virtual void render(IRenderer renderer, bool is_world_space) const = 0;
};

#endif //ENGINE_IRENDERABLE_HPP
