#ifndef P_INPUT_CONVERSION_HPP
#define P_INPUT_CONVERSION_HPP

#include <string>
#include "SDL.h"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"

SDL_KeyCode parse_numeric_keys(Key key){
    switch(key){
        case NUM_0:
            return static_cast<SDL_KeyCode>(SDLK_0);
        case NUM_1:
            return static_cast<SDL_KeyCode>(SDLK_1);
        case NUM_2:
            return static_cast<SDL_KeyCode>(SDLK_2);
        case NUM_3:
            return static_cast<SDL_KeyCode>(SDLK_3);
        case NUM_4:
            return static_cast<SDL_KeyCode>(SDLK_4);
        case NUM_5:
            return static_cast<SDL_KeyCode>(SDLK_5);
        case NUM_6:
            return static_cast<SDL_KeyCode>(SDLK_6);
        case NUM_7:
            return static_cast<SDL_KeyCode>(SDLK_7);
        case NUM_8:
            return static_cast<SDL_KeyCode>(SDLK_8);
        default:
            return static_cast<SDL_KeyCode>(SDLK_9);

    }
};
SDL_KeyCode parse_alpha_keys(Key key){
    switch(key){
        case A:
            return static_cast<SDL_KeyCode>(SDLK_a);
        case B:
            return static_cast<SDL_KeyCode>(SDLK_b);
        case C:
            return static_cast<SDL_KeyCode>(SDLK_c);
        case D:
            return static_cast<SDL_KeyCode>(SDLK_d);
        case E:
            return static_cast<SDL_KeyCode>(SDLK_e);
        case F:
            return static_cast<SDL_KeyCode>(SDLK_f);
        case G:
            return static_cast<SDL_KeyCode>(SDLK_g);
        case H:
            return static_cast<SDL_KeyCode>(SDLK_h);
        case I:
            return static_cast<SDL_KeyCode>(SDLK_i);
        case J:
            return static_cast<SDL_KeyCode>(SDLK_j);
        case K:
            return static_cast<SDL_KeyCode>(SDLK_k);
        case L:
            return static_cast<SDL_KeyCode>(SDLK_l);
        case M:
            return static_cast<SDL_KeyCode>(SDLK_m);
        case N:
            return static_cast<SDL_KeyCode>(SDLK_n);
        case O:
            return static_cast<SDL_KeyCode>(SDLK_o);
        case P:
            return static_cast<SDL_KeyCode>(SDLK_p);
        case Q:
            return static_cast<SDL_KeyCode>(SDLK_q);
        case R:
            return static_cast<SDL_KeyCode>(SDLK_r);
        case S:
            return static_cast<SDL_KeyCode>(SDLK_s);
        case T:
            return static_cast<SDL_KeyCode>(SDLK_t);
        case U:
            return static_cast<SDL_KeyCode>(SDLK_u);
        case V:
            return static_cast<SDL_KeyCode>(SDLK_v);
        case W:
            return static_cast<SDL_KeyCode>(SDLK_w);
        case Y:
            return static_cast<SDL_KeyCode>(SDLK_x);
        case X:
            return static_cast<SDL_KeyCode>(SDLK_y);
        default:
            return static_cast<SDL_KeyCode>(SDLK_z);
    }
};
SDL_KeyCode parse_function_keys(Key key){
    switch(key){
        case UP:
            return static_cast<SDL_KeyCode>(SDLK_UP);
        case LEFT:
            return static_cast<SDL_KeyCode>(SDLK_LEFT);
        case RIGHT:
            return static_cast<SDL_KeyCode>(SDLK_RIGHT);
        case DOWN:
            return static_cast<SDL_KeyCode>(SDLK_DOWN);
        case SPACE:
            return static_cast<SDL_KeyCode>(SDLK_SPACE);
        case ENTER:
            return static_cast<SDL_KeyCode>(SDLK_RETURN);
        case MIN:
            return static_cast<SDL_KeyCode>(SDLK_MINUS);
        case PLUS:
            return static_cast<SDL_KeyCode>(SDLK_PLUS);
        case EQUAL:
            return static_cast<SDL_KeyCode>(SDLK_EQUALS);
        case SHIFT_RIGHT:
            return static_cast<SDL_KeyCode>(SDLK_RSHIFT);
        case SHIFT_LEFT:
            return static_cast<SDL_KeyCode>(SDLK_LSHIFT);
        case CTRL_RIGHT:
            return static_cast<SDL_KeyCode>(SDLK_RCTRL);
        case CTRL_LEFT:
            return static_cast<SDL_KeyCode>(SDLK_LCTRL);
        case ALT:
            return static_cast<SDL_KeyCode>(SDLK_LALT);
        case TAB:
            return static_cast<SDL_KeyCode>(SDLK_TAB);
        default:
            return static_cast<SDL_KeyCode>(SDLK_ESCAPE);
    }
};
SDL_KeyCode parse_key(Key key){
    std::string strCheck = ""+key;
    if(strCheck.length() == 1)
        return parse_alpha_keys(key);

    if(strCheck.substr(0,3) == "NUM")
        return parse_numeric_keys(key);

    return parse_function_keys(key);
};
int parse_mouseinput(MouseInput input){
    switch(input){
        case Left:
            return SDL_BUTTON_LEFT;
        case Right:
            return SDL_BUTTON_RIGHT;
        default:
            return SDL_BUTTON_MIDDLE;
    }
};

#endif //P_INPUT_CONVERSION_HPP