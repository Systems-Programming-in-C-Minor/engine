#include "UIObject.hpp"

UIObject::UIObject(double width, double height) :
    width(width),
    height(height) {}

UIObject::UIObject() {}

double UIObject::getHeight() const {
    return height;
}

double UIObject::getWidth() const {
    return width;
}

void UIObject::setHeight(double newHeight) {
    height = newHeight;
}

void UIObject::setWidth(double newWidth) {
    width = newWidth;
}
