
#ifndef ENGINE_MOUSE_HANDLER_HPP
#define ENGINE_MOUSE_HANDLER_HPP

#include <vector>
#include "../include/enums/mouse_input.hpp"

/**
 * @brief A handler for mouse input.
 */
class MouseHandler {
private:
    int _x, _y;
    std::vector<MouseInput> _input_active;

    /**
     * @brief Method which fetches the mouse input.
     * @return A vector containing all registered mouse input.
     * */
    std::vector<MouseInput> fetch_input();

public:
    /**
     * @brief Method which gets called every tick.
     * */
    void tick();
};

#endif //ENGINE_MOUSE_HANDLER_HPP
