
#ifndef ENGINE_MOUSE_HANDLER_HPP
#define ENGINE_MOUSE_HANDLER_HPP

#include <vector>
#include "../include/enums/mouse_input.hpp"

class MouseHandler {
private:
    int *_x;
    int *_y;
    std::vector<MouseInput> _input_active;

    std::vector<MouseInput> fetch_input() ;

public:
    void tick();
};

#endif //ENGINE_MOUSE_HANDLER_HPP
