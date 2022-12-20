#ifndef ENGINE_IRENDERABLE_HPP
#define ENGINE_IRENDERABLE_HPP

#include "render/irenderer.hpp"

/**
 * @brief Interface for objects which are renderable.
 */
class IRenderable {
public:
    /**
     * @brief Render the IRenderable object.
     *        Override for implementing the desired behaviour.
     */
    virtual void render() = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IRenderable() = default;

    /**
     * @brief Return the order_in_layer variable.
     *        Override for implementing the desired behaviour.
     * @return The current order_in_layer.
     */
    virtual int get_order_in_layer()
    {
        return _order_in_layer;
    }
protected:
    /**
     * @brief The order in layer in which the IRenderable will be rendered.
     */
    int _order_in_layer;

    /**
     * @brief Inline constructor.
     */
    inline IRenderable(int order_in_layer) { _order_in_layer = order_in_layer; }
};



#endif //ENGINE_IRENDERABLE_HPP
