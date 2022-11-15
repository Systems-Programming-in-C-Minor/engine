#include "uiobject.hpp"

double UIObject::get_height() const {
    return height;
}

double UIObject::get_width() const {
    return width;
}

void UIObject::set_height(double new_height) {
    height = new_height;
}

void UIObject::set_width(double new_width) {
    width = new_width;
}
