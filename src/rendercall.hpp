#ifndef ENGINE_RENDERCALL_HPP
#define ENGINE_RENDERCALL_HPP

#include <functional>

class RenderCall {
public:
    std::function<void()> render_callback;
    int order_in_layer;

    /**
     * @brief A drawcall to the renderer for an IRenderable
     * @param render_callback A callback to the actual render call, with stored capture list
     * @param order_in_layer The order in layer, or Z-order of the IRenderable
     */
    explicit RenderCall(std::function<void()> render_callback, int order_in_layer);
};


#endif //ENGINE_RENDERCALL_HPP
