#include "input.hpp"
#include "SDL.h"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "transform.hpp"
#include <math.h>
#include "../p_headers/input_conversion.h"

const Uint8* Input::fetch_state(){
    SDL_PumpEvents();
    return SDL_GetKeyboardState(nullptr);
}

bool Input::any_key(){
    const Uint8* current_state = fetch_state();
    while(current_state){
        if (*current_state == static_cast<Uint8>(1)) {
            return true;
        }
        current_state++;
    }
    return false;
}

//bool Input::any_key_down(){
//    const Uint8* current_state = fetch_state();
//    while(current_state){
//        if (*current_state == static_cast<Uint8>(1)) {
//            return true;
//        }
//        current_state++;
//    }
//    return false;
//}

Vector2d Input::mouse_position() {
    int x,y;
    SDL_GetMouseState(&x, &y);
    Vector2d vec { (float) x,(float) y};
    return vec;
}

double Input::get_axis() {
    Sint32 xrel, yrel;

    return sqrt((xrel*xrel)+(yrel*yrel));
}

bool Input::get_key(Key key) {
    return false;
}

bool Input::get_key_down(Key key) {
    return false;
}

bool Input::get_key_up(Key key) {
    return false;
}

bool Input::get_mouse_button(MouseInput which) {
    return false;
}

bool Input::get_mouse_button_down(MouseInput which) {
    return false;
}

bool Input::get_mouse_button_up(MouseInput which) {
    return false;
}