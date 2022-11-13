#include "uiobjects/Button.hpp"

Button::Button(bool interactable) :
    interactable(interactable) {}

void Button::Click(){
    if(interactable)
    {
        onClick();
    }
}
