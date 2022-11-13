#pragma once

#include "UIObject.hpp"
#include "enums/Alignment.hpp"

/**
     * @brief Class representing a piece of text which can be rendered.
*/
class Text {
public:
    Text(std::string text, std::string font, int size, Alignment alignment);
    [[nodiscard]] const std::string getText() { return text; }
    [[nodiscard]] const std::string getFont() { return font; }
    [[nodiscard]] const int getSize() { return size; }
    [[nodiscard]] const Alignment getAlignment() { return alignment; }
    void setText(std::string newText) { text = newText; }
    void setFont(std::string newFont) { font = newFont; }
    void setSize(int newSize) { size = newSize; }
    void setAlignment(Alignment newAlignment) { alignment = newAlignment; }
private:
    std::string text;
    std::string font;
    int size;
    Alignment alignment;
};
