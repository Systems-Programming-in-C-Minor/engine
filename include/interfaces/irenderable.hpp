#ifndef ENGINE_IRENDERABLE_HPP
#define ENGINE_IRENDERABLE_HPP

#include "render/irenderer.hpp"

class IRenderable {
public:
    virtual void render() = 0;
    virtual ~IRenderable() = default;
    virtual int get_order_in_layer()
    {
        return _order_in_layer;
    }
protected:
    int _order_in_layer;
    inline IRenderable(int order_in_layer) { _order_in_layer = order_in_layer; }
};



#endif //ENGINE_IRENDERABLE_HPP
