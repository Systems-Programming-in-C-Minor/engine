#include "uiobjects/button.hpp"
#include "uiobject.hpp"

Button::Button(const std::string& name, const std::string& tag, double width, double height, bool interactable) : UIObject(name, tag, width, height),
    _on_click({[]() {}}),
    _interactable(interactable)
{}

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
