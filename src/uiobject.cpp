#include "uiobject.hpp"

UIObject::UIObject(const std::string &name, const std::string &tag, int width, int height) : GameObject(name, tag),
    _width(width),
    _height(height) {}

int UIObject::get_height() const {
    return _height;
}

int UIObject::get_width() const {
    return _width;
}

void UIObject::set_height(int new_height) {
    _height = new_height;
}

void UIObject::set_width(int new_width) {
    _width = new_width;
}
