#include "uiobjects/Text.hpp"

#include <string>

Text::Text(std::string text, std::string font, int size, Alignment alignment) :
    text(text),
    font(font),
    size(size),
    alignment(alignment) {}
