#include "input.hpp"
#include "SDL.h"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "transform.hpp"

std::vector<Key> Input::fetch_keystate() {
    const Uint8 *current_key_states = SDL_GetKeyboardState(nullptr);

    std::vector<Key> keys_pressed;

    if (current_key_states[SDL_SCANCODE_0])
        keys_pressed.emplace_back(NUM_0);
    if (current_key_states[SDL_SCANCODE_1])
        keys_pressed.emplace_back(NUM_1);
    if (current_key_states[SDL_SCANCODE_2])
        keys_pressed.emplace_back(NUM_2);
    if (current_key_states[SDL_SCANCODE_3])
        keys_pressed.emplace_back(NUM_3);
    if (current_key_states[SDL_SCANCODE_4])
        keys_pressed.emplace_back(NUM_4);
    if (current_key_states[SDL_SCANCODE_5])
        keys_pressed.emplace_back(NUM_5);
    if (current_key_states[SDL_SCANCODE_6])
        keys_pressed.emplace_back(NUM_6);
    if (current_key_states[SDL_SCANCODE_7])
        keys_pressed.emplace_back(NUM_7);
    if (current_key_states[SDL_SCANCODE_8])
        keys_pressed.emplace_back(NUM_8);
    if (current_key_states[SDL_SCANCODE_9])
        keys_pressed.emplace_back(NUM_9);
    if (current_key_states[SDL_SCANCODE_A])
        keys_pressed.emplace_back(A);
    if (current_key_states[SDL_SCANCODE_B])
        keys_pressed.emplace_back(B);
    if (current_key_states[SDL_SCANCODE_C])
        keys_pressed.emplace_back(C);
    if (current_key_states[SDL_SCANCODE_D])
        keys_pressed.emplace_back(D);
    if (current_key_states[SDL_SCANCODE_E])
        keys_pressed.emplace_back(E);
    if (current_key_states[SDL_SCANCODE_F])
        keys_pressed.emplace_back(F);
    if (current_key_states[SDL_SCANCODE_G])
        keys_pressed.emplace_back(G);
    if (current_key_states[SDL_SCANCODE_H])
        keys_pressed.emplace_back(H);
    if (current_key_states[SDL_SCANCODE_I])
        keys_pressed.emplace_back(I);
    if (current_key_states[SDL_SCANCODE_J])
        keys_pressed.emplace_back(J);
    if (current_key_states[SDL_SCANCODE_K])
        keys_pressed.emplace_back(K);
    if (current_key_states[SDL_SCANCODE_L])
        keys_pressed.emplace_back(L);
    if (current_key_states[SDL_SCANCODE_M])
        keys_pressed.emplace_back(M);
    if (current_key_states[SDL_SCANCODE_N])
        keys_pressed.emplace_back(N);
    if (current_key_states[SDL_SCANCODE_O])
        keys_pressed.emplace_back(O);
    if (current_key_states[SDL_SCANCODE_P])
        keys_pressed.emplace_back(P);
    if (current_key_states[SDL_SCANCODE_Q])
        keys_pressed.emplace_back(Q);
    if (current_key_states[SDL_SCANCODE_R])
        keys_pressed.emplace_back(R);
    if (current_key_states[SDL_SCANCODE_S])
        keys_pressed.emplace_back(S);
    if (current_key_states[SDL_SCANCODE_T])
        keys_pressed.emplace_back(T);
    if (current_key_states[SDL_SCANCODE_U])
        keys_pressed.emplace_back(U);
    if (current_key_states[SDL_SCANCODE_V])
        keys_pressed.emplace_back(V);
    if (current_key_states[SDL_SCANCODE_W])
        keys_pressed.emplace_back(W);
    if (current_key_states[SDL_SCANCODE_X])
        keys_pressed.emplace_back(X);
    if (current_key_states[SDL_SCANCODE_Y])
        keys_pressed.emplace_back(Y);
    if (current_key_states[SDL_SCANCODE_Z])
        keys_pressed.emplace_back(Z);
    if (current_key_states[SDL_SCANCODE_UP])
        keys_pressed.emplace_back(UP);
    if (current_key_states[SDL_SCANCODE_RIGHT])
        keys_pressed.emplace_back(RIGHT);
    if (current_key_states[SDL_SCANCODE_DOWN])
        keys_pressed.emplace_back(DOWN);
    if (current_key_states[SDL_SCANCODE_LEFT])
        keys_pressed.emplace_back(LEFT);
    if (current_key_states[SDL_SCANCODE_SPACE])
        keys_pressed.emplace_back(SPACE);
    if (current_key_states[SDL_SCANCODE_RETURN])
        keys_pressed.emplace_back(ENTER);
    if (current_key_states[SDL_SCANCODE_MINUS])
        keys_pressed.emplace_back(MIN);
    if (current_key_states[SDL_SCANCODE_EQUALS])
        keys_pressed.emplace_back(EQUAL);
    if (current_key_states[SDL_SCANCODE_RSHIFT])
        keys_pressed.emplace_back(SHIFT_RIGHT);
    if (current_key_states[SDL_SCANCODE_LSHIFT])
        keys_pressed.emplace_back(SHIFT_LEFT);
    if (current_key_states[SDL_SCANCODE_RCTRL])
        keys_pressed.emplace_back(CTRL_RIGHT);
    if (current_key_states[SDL_SCANCODE_LCTRL])
        keys_pressed.emplace_back(CTRL_LEFT);
    if (current_key_states[SDL_SCANCODE_RALT])
        keys_pressed.emplace_back(ALT_RIGHT);
    if (current_key_states[SDL_SCANCODE_LALT])
        keys_pressed.emplace_back(ALT_LEFT);
    if (current_key_states[SDL_SCANCODE_TAB])
        keys_pressed.emplace_back(TAB);
    if (current_key_states[SDL_SCANCODE_ESCAPE])
        keys_pressed.emplace_back(ESC);

    return keys_pressed;
}

std::vector<MouseInput> Input::fetch_mousestate(){
    std::vector<MouseInput> current_mousestate;

    auto mState = SDL_GetMouseState(NULL,NULL);
    if(mState & SDL_BUTTON_LMASK)
        current_mousestate.emplace_back(BUTTON_LEFT);
    if(mState & SDL_BUTTON_MMASK)
        current_mousestate.emplace_back(BUTTON_MIDDLE);
    if(mState & SDL_BUTTON_RMASK)
        current_mousestate.emplace_back(BUTTON_RIGHT);

    return current_mousestate;
}

bool Input::any_key(){
    std::vector<Key> current_keystate = fetch_keystate();
    std::vector<MouseInput> current_mousestate = fetch_mousestate();

    _previous_keystate = current_keystate;
    return !current_keystate.empty();
}

bool Input::any_key_down(){
    auto current_keystate = fetch_keystate();
    bool res = false;
    for(const auto input: current_keystate){
        // if key is pressed in current state, but not in previous state, return true
        if(std::find(_previous_keystate.begin(), _previous_keystate.end(), input) == _previous_keystate.end()){
            res = true;
        }
    }
    _previous_keystate = current_keystate;

    auto current_mousestate = fetch_mousestate();
    for(const auto input: current_mousestate){
        if(std::find(_previous_mousestate.begin(), _previous_mousestate.end(), input) == _previous_mousestate.end()){
            res = true;
        }
    }
    _previous_mousestate = current_mousestate;
    return res;
}

Vector2d Input::mouse_position() {
    int x,y;
    SDL_GetMouseState(&x, &y);
    Vector2d vec { (float) x,(float) y};
    return vec;
}

bool Input::get_key(Key key) {
    auto current_keystate = fetch_keystate();
    _previous_keystate = current_keystate;
    return std::find(current_keystate.begin(), current_keystate.end(), key) != current_keystate.end();
}

bool Input::get_key_down(Key key) {
    // If key is not in previous state, but is pressed this state, it is pressed this frame
    auto current_keystate = fetch_keystate();
    bool res = true;

    if(std::find(_previous_keystate.begin(), _previous_keystate.end(), key) != _previous_keystate.end())
        res = false;

    if (std::find(current_keystate.begin(), current_keystate.end(), key) == current_keystate.end())
        res = false;

    _previous_keystate = current_keystate;
    return res;
}

bool Input::get_key_up(Key key) {
    // If key is in previous state, but is not pressed this state, it is released this frame
    auto current_keystate = fetch_keystate();

    if(std::find(current_keystate.begin(), current_keystate.end(), key) != current_keystate.end())
        return false;

    if(std::find(_previous_keystate.begin(), _previous_keystate.end(), key) == _previous_keystate.end())
        return false;

    _previous_keystate = current_keystate;
    return true;
}

bool Input::get_mouse_button(MouseInput which) {
    auto current_mousestate = fetch_mousestate();

    _previous_mousestate = current_mousestate;

    return std::find(current_mousestate.begin(), current_mousestate.end(), which) != current_mousestate.end();
}

bool Input::get_mouse_button_down(MouseInput which) {
    auto current_mousestate = fetch_mousestate();
    bool res = true;

    // If mousebutton is not in previous state, but is in this state, it is pressed this frame
    if (std::find(_previous_mousestate.begin(), _previous_mousestate.end(), which) != _previous_mousestate.end())
        res = false;

    if (std::find(current_mousestate.begin(), current_mousestate.end(), which) == current_mousestate.end())
        res = false;

    _previous_mousestate = current_mousestate;
    return res;
}

bool Input::get_mouse_button_up(MouseInput which) {
    auto current_mousestate = fetch_mousestate();
    bool res = true;
    // If mousebutton is in previous state, but not in this state, it is released this frame
    if (std::find(current_mousestate.begin(), current_mousestate.end(), which) != current_mousestate.end())
        res = false;

    if (std::find(_previous_mousestate.begin(), _previous_mousestate.end(), which) == _previous_mousestate.end())
        res = false;

    _previous_mousestate = current_mousestate;
    return true;
}