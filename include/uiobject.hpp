#pragma once

#include "gameobject.hpp"

/**
 * @brief Base class for a user interface object like Button or Text.
 */
class UIObject : public GameObject {
private:
    double width;
    double height;
public:
    void set_width(double new_width);
    [[nodiscard]] double get_width() const;
    void set_height(double new_height);
    [[nodiscard]] double get_height() const;
};
