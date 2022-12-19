#pragma once

#include "gameobject.hpp"

    /**
     * @brief Base class for a user interface object like Button or Text.
     */
class UIObject : public GameObject {
private:
    int _width;
    int _height;
public:
    /**
     * @brief Constructor.
     * @param name The name of the text GameObject.
     * @param tag The tag of the text GameObject.
     * @param is_world_space Boolean option if the text will be rendered in world space.
     * @param transform The transform of the text.
     * @param width The width of the text.
     * @param height The height of the text.
     */
    UIObject(const std::string& name, const std::string& tag, bool is_world_space, Transform transform, int width, int height);

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
};
