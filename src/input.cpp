#include "input.hpp"

#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "transform.hpp"
#include "SDL.h"
#include <math.h>

Input::~Input() {
    delete _event;
}

bool Input::any_key(){
    SDL_PollEvent(_event);
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
    Sint32 xrel, yrel;
    xrel = _event->motion.xrel;
    yrel = _event->motion.yrel;

    return sqrt((xrel*xrel)+(yrel*yrel));
}

bool Input::get_key(Key key) {
    SDL_PollEvent(_event);
    if(_event->type == SDL_KEYDOWN){
        std::string str = ""+_event->key.keysym.sym;
        return str == parse_key(key);
    }
    return false;
}

bool Input::get_key_down(Key key) {
    SDL_PollEvent(_event);
    if(_event->type == SDL_KEYDOWN){
        std::string str = ""+_event->key.keysym.sym;
     return str == parse_key(key);
    }
}

bool Input::get_key_up(Key key) {
    SDL_PollEvent(_event);
    if(_event->type == SDL_KEYUP){
        std::string str = ""+_event->key.keysym.sym;
        return str == parse_key(key);
    }
}

bool Input::get_mouse_button(MouseInput which) {
    SDL_PollEvent(_event);
    if(_event->type == SDL_MOUSEBUTTONDOWN){
        std::string str = ""+_event->key.keysym.sym;
        return str == parse_mouseinput(which);
    }
}

bool Input::get_mouse_button_down(MouseInput which) {
    SDL_PollEvent(_event);
    if(_event->type == SDL_MOUSEBUTTONDOWN){
        std::string str = ""+_event->key.keysym.sym;
        return str == parse_mouseinput(which);
    }
}

bool Input::get_mouse_button_up(MouseInput which) {
    SDL_PollEvent(_event);
    if(_event->type == SDL_MOUSEBUTTONUP){
        std::string str = ""+_event->key.keysym.sym;
        return str == parse_mouseinput(which);
    }
}

std::string Input::parse_key(Key key) {
    std::string strCheck = ""+key;
    if(strCheck.length() == 1)
        return parse_alpha_keys(key);

    if(strCheck.substr(0,3) == "NUM")
        return parse_numeric_keys(key);

    else return parse_function_keys(key);
}

std::string Input::parse_alpha_keys(Key key) {
    std::string str_key = ""+key;
    std::transform(str_key.begin(), str_key.end(), str_key.begin(),
        [](unsigned char c){ return std::tolower(c); }
    );

    return "SDLK_"+str_key;
}

std::string Input::parse_numeric_keys(Key key) {
    std::string str_key = ""+key;
    str_key = str_key.substr(str_key.length()-1,1);

    return "SDLK_"+str_key;
}

std::string Input::parse_function_keys(Key key) {
    std::string str_key = "SDLK_";

    switch(key){
        case UP:
            return str_key+"UP";
            break;
        case LEFT:
            return str_key+"LEFT";
            break;
        case RIGHT:
            return str_key+"RIGHT";
            break;
        case DOWN:
            return str_key+"RIGHT";
            break;
        case SPACE:
            return str_key+"SPACE";
            break;
        case ENTER:
            return str_key+"RETURN";
            break;
        case MIN:
            return str_key+"MINUS";
            break;
        case PLUS:
            return str_key+"PLUS";
            break;
        case EQUAL:
            return str_key+"EQUALS";
            break;
        case SHIFT_RIGHT:
            return str_key+"RSHIFT";
            break;
        case SHIFT_LEFT:
            return str_key+"LSHIFT";
            break;
        case CTRL_RIGHT:
            return str_key+"RCTRL";
            break;
        case CTRL_LEFT:
            return str_key+"LCTRL";
            break;
        case ALT:
            return str_key+"LALT";
            break;
        case TAB:
            return str_key+"TAB";
            break;
        case ESC:
            return str_key+"ESCAPE";
            break;
    }

    return str_key;
}

std::string Input::parse_mouseinput(MouseInput input) {
    std::string mouse_input = "SDL_BUTTON_";

    switch(input){
        case Left:
            return mouse_input+"LEFT";
            break;
        case Right:
            return mouse_input+"RIGHT";
            break;
        case Middle:
            return mouse_input+"MIDDLE";
            break;
    }

    return mouse_input;
}