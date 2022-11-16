#pragma once

#include "gameobject.hpp"

/**
 * @brief Base class for a user interface object like Button or Text.
 */
class UIObject : public GameObject {
private:
    double _width;
    double _height;
public:
    UIObject(const std::string& name, const std::string& tag, double width, double height);
    void set_width(double new_width);
    [[nodiscard]] double get_width() const;
    void set_height(double new_height);
    [[nodiscard]] double get_height() const;
};
