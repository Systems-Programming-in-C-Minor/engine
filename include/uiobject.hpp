#pragma once

#include "gameobject.hpp"
#include "listeners/mouse_listener.hpp"

/**
 * @brief Base class for a user interface object like Button or Text.
 */
class UIObject : public GameObject, public MouseListener {
private:
    int _width;
    int _height;

    bool is_in_object(int x, int y) const;
public:
    UIObject(const std::string& name, const std::string& tag, int width, int height, EventManager &event_manager, Transform transform = Transform{});
    void set_width(int new_width);
    [[nodiscard]] int get_width() const;
    void set_height(int new_height);
    [[nodiscard]] int get_height() const;
    void on_mouse_pressed(const MousePressedEvent &event) override;
    void on_mouse_released(const MouseReleasedEvent & event) override;
    virtual ~UIObject() override;
};
