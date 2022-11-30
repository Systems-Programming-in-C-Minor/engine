#include "input.hpp"

#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "transform.hpp"
#include "SDL.h"

Input::~Input() {
    delete _event;
}

bool Input::any_key(){
    if(_event->type == SDL_KEYDOWN || _event->type == SDL_MOUSEBUTTONDOWN){
        return true;
    }
    return false;
}

bool Input::any_key_down(){
    return (SDL_PollEvent(_event) && any_key());
}

Vector2d Input::mouse_position() {
    int x,y;
    SDL_GetMouseState(&x, &y);
    Vector2d vec {(double) x,(double) y};
    return vec;
}

double Input::get_axis() {
    if (_event->type == SDL_MOUSEMOTION) {

    }
}

bool Input::get_key(Key key) {
    SDL_Keysym *keysym = new SDL_Keysym();
    keysym->sym = key;
    SDL_KeyboardEvent keyEvent {};

    if(&_event->key.keysym == keysym){

    }

}

bool Input::get_key_down(Key key) {

}

bool Input::get_key_up(Key key) {

}

bool Input::get_mouse_button(MouseInput which) {

}

bool Input::get_mouse_button_down(MouseInput which) {

}

bool Input::get_mouse_button_up(MouseInput which) {

}

