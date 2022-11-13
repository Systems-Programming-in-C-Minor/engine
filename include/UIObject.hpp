#pragma once

#include "GameObject.hpp"

/**
 * @brief Base class for a user interface object like Button or Text.
*/
class UIObject : public GameObject {
public:
    UIObject(double width, double height);
    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;
    void setWidth(double newWidth);
    void setHeight(double newHeight);
private:
    double width;
    double height;
};
