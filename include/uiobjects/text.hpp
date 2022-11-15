#pragma once

#include "uiobject.hpp"
#include "enums/alignment.hpp"

/**
 * @brief Class representing a piece of text which can be rendered.
*/
class Text : public UIObject {
private:
    std::string _text;
    std::string _font;
    int _size;
    Alignment _alignment;
//    Color color;
public:
    [[nodiscard]] std::string get_text() const;
    [[nodiscard]] std::string get_font() const;
    [[nodiscard]] int get_size() const;
    [[nodiscard]] Alignment get_alignment() const;
    void set_text(std::string new_text);
    void set_font(std::string new_font);
    void set_size(int new_size);
    void set_alignment(Alignment new_alignment);
};
