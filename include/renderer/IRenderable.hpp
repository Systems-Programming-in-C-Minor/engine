//
// Created by lars on 13-11-22.
//

#ifndef ENGINE_IRENDERABLE_HPP
#define ENGINE_IRENDERABLE_HPP

#include "IRenderer.hpp"

class IRenderable {

    virtual void render(IRenderer renderer, bool isWorldSpace = true) const = 0;

};

#endif //ENGINE_IRENDERABLE_HPP
