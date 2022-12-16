#pragma once

#include "gameobject.hpp"
#include "enums/spaces.hpp"

/**
 * @brief Base class for a user interface object like Button or Text.
 */
class UIObject : public GameObject {
private:
    int _width;
    int _height;
    Space _space;
public:
    UIObject(const std::string& name, const std::string& tag, bool is_world_space, Transform transform, int width, int height, Space space = Space::SCREEN);
    void set_width(int new_width);
    [[nodiscard]] int get_width() const;
    void set_height(int new_height);
    [[nodiscard]] int get_height() const;
    [[nodiscard]] Space get_space() const;
    virtual ~UIObject() override;
};
