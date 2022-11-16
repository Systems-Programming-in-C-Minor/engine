#include "uiobject.hpp"

UIObject::UIObject(const std::string &name, const std::string &tag, double width, double height) : GameObject(name, tag),
    _width(width),
    _height(height) {}

double UIObject::get_height() const {
    return _height;
}

double UIObject::get_width() const {
    return _width;
}

void UIObject::set_height(double new_height) {
    _height = new_height;
}

void UIObject::set_width(double new_width) {
    _width = new_width;
}
