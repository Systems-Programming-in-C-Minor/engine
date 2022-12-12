#include "rendercall.hpp"

RenderCall::RenderCall(std::function<void()> render_callback, int order_in_layer)
        : render_callback(std::move(render_callback)), order_in_layer(order_in_layer) {}