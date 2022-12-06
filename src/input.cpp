#include "input.hpp"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "transform.hpp"
#include "SDL.h"
#include <math.h>
#include "../p_headers/input_conversion.h"

bool Input::any_key(){
    SDL_Event* _event;
    SDL_PollEvent(_event);
    if(_event->type == SDL_KEYDOWN || _event->type == SDL_MOUSEBUTTONDOWN){
        return true;
    }
    return false;
}

bool Input::any_key_down(){
    SDL_Event* _event;
    return (SDL_PollEvent(_event) && any_key());
}

Vector2d Input::mouse_position() {
    int x,y;
    SDL_GetMouseState(&x, &y);
    Vector2d vec { (float) x,(float) y};
    return vec;
}

double Input::get_axis() {
    SDL_Event* _event;
    Sint32 xrel, yrel;
    xrel = _event->motion.xrel;
    yrel = _event->motion.yrel;

    return sqrt((xrel*xrel)+(yrel*yrel));
}

bool Input::get_key(Key key) {
    SDL_Event* _event;
    SDL_PollEvent(_event);
    if(_event->type == SDL_KEYDOWN){
        return _event->key.keysym.sym == parse_key(key);
    }
    return false;
}

bool Input::get_key_down(Key key) {
    SDL_Event* _event;
    SDL_PollEvent(_event);
    if(_event->type == SDL_KEYDOWN){
        return _event->key.keysym.sym == parse_key(key);
    }
    return false;
}

bool Input::get_key_up(Key key) {
    SDL_Event* _event;
    SDL_PollEvent(_event);
    if(_event->type == SDL_KEYUP){
        return _event->key.keysym.sym == parse_key(key);
    }
    return false;
}

bool Input::get_mouse_button(MouseInput which) {
    SDL_Event* _event;
    SDL_PollEvent(_event);
    if(_event->type == SDL_MOUSEBUTTONDOWN){
        return _event->button.button == parse_mouseinput(which);
    }
    return false;
}

bool Input::get_mouse_button_down(MouseInput which) {
    SDL_Event* _event;
    SDL_PollEvent(_event);
    if(_event->type == SDL_MOUSEBUTTONDOWN){
        return _event->button.button == parse_mouseinput(which);
    }
    return false;
}

bool Input::get_mouse_button_up(MouseInput which) {
    SDL_Event* _event;
    SDL_PollEvent(_event);
    if(_event->type == SDL_MOUSEBUTTONUP){
        return _event->button.button == parse_mouseinput(which);
    }
    return false;
}