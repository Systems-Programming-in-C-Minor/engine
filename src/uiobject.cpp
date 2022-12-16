#include "uiobject.hpp"

UIObject::UIObject(const std::string &name, const std::string &tag, bool is_world_space, Transform transform, int width, int height, Space space) :
	GameObject(name, tag, is_world_space, transform),
    _width(width),
    _height(height),
	_space(space)
{}

int UIObject::get_height() const {
    return _height;
}

Space UIObject::get_space() const
{
    return _space;
}

UIObject::~UIObject() = default;

int UIObject::get_width() const {
    return _width;
}

void UIObject::set_height(int new_height) {
    _height = new_height;
}

void UIObject::set_width(int new_width) {
    _width = new_width;
}
