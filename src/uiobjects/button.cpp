#include "uiobjects/button.hpp"

void Button::set_interactable(bool is_interactable) {
    _interactable = is_interactable;
}

bool Button::get_interactable() const {
    return _interactable;
}

void Button::click() {
    if(_interactable)
    {
        _on_click();
    }
}
