#include "uiobject.hpp"

#include <iostream>

#include "global.hpp"

UIObject::UIObject(const std::string &name, const std::string &tag, int width, int height, EventManager &event_manager, Transform transform) :
	GameObject(name, tag, transform),
	MouseListener(event_manager),
    _width(width),
    _height(height)
{}

UIObject::~UIObject() = default;

int UIObject::get_height() const {
    return _height;
}

void UIObject::on_mouse_pressed(const MousePressedEvent& event)
{
    if(is_in_object(event.x, event.y))
    {
        Global::get_instance()->notify_event_manager(UiObjectPressedEvent{ event.button, *this });
    }
}

void UIObject::on_mouse_released(const MouseReleasedEvent& event)
{
    if (is_in_object(event.x, event.y))
    {
        Global::get_instance()->notify_event_manager(UiObjectReleasedEvent{ event.button, *this });
    }
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

bool UIObject::is_in_object(int x, int y) const
{
    const auto renderer = Global::get_instance()->get_engine().get_renderer();
    const Vector2d position = renderer->screen_to_screen_space(Vector2d{
        static_cast<float>(x),
        static_cast<float>(y)
    });
     
    const float left_corner_x = transform.get_position().x + -static_cast<float>(_width) * transform.get_scale() / 2.f;
    const float left_corner_y = transform.get_position().y + -static_cast<float>(_height) * transform.get_scale() / 2.f;

    const float right_corner_x = transform.get_position().x + static_cast<float>(_width) * transform.get_scale() / 2.f;
    const float right_corner_y = transform.get_position().y + static_cast<float>(_height) * transform.get_scale() / 2.f;

    if (position.x > left_corner_x &&
        position.x < right_corner_x &&
        position.y > left_corner_y &&
        position.y < right_corner_y)
    {
        return true;
    }
    return false;
}
