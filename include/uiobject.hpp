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
    UIObject(const std::string& name, const std::string& tag, int width, int height);
    void set_width(int new_width);
    [[nodiscard]] int get_width() const;
    void set_height(int new_height);
    [[nodiscard]] int get_height() const;
};
