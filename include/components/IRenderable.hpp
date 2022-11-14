#ifndef ENGINE_IRENDERABLE_HPP
#define ENGINE_IRENDERABLE_HPP

// TODO remove when IRenderer is implemented
class IRenderer;

class IRenderable {

    virtual void render(IRenderer renderer, bool isWorldSpace = true) = 0;

};

#endif //ENGINE_IRENDERABLE_HPP
