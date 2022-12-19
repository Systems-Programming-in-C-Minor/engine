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
    /**
     * @brief Constructor.
     * @param name The name of the text GameObject.
     * @param tag The tag of the text GameObject.
     * @param width The width of the text.
     * @param height The height of the text.
     */
    UIObject(const std::string& name, const std::string& tag, int width, int height, EventManager &event_manager, Transform transform = Transform{});

    /**
     * @brief Setter for the width of the ui object.
     * @param new_width The new width which will be set.
     */
    void set_width(int new_width);

    /**
     * @brief Getter for the width of the ui object.
     * @return Return the width as an int value.
     */
    [[nodiscard]] int get_width() const;

    /**
     * @brief Setter for the height of the ui object.
     * @param new_height The new height which will be set.
     */
    void set_height(int new_height);

    /**
     * @brief Getter for the height of the ui object.
     * @return Return the height as an int value.
     */
    [[nodiscard]] int get_height() const;
    void on_mouse_pressed(const MousePressedEvent &event) override;
    void on_mouse_released(const MouseReleasedEvent & event) override;
    virtual ~UIObject() override;
};
