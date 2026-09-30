#include "Label.hpp"
#include "raylib.h"

Label::Label(Layout layout, const std::string& text, Color color, int fontSize)
    : UIElement({0, 0, 0, 0}, layout),
      text(text),
      fontSize(fontSize),
      color(color) {
    preferredBounds = {
        0.0f, 0.0f,
        static_cast<float>(MeasureText(text.c_str(), fontSize)),
        static_cast<float>(fontSize)
    };
}

void Label::draw()
{
    DrawText(
        text.c_str(),
        static_cast<int>(bounds.x),
        static_cast<int>(bounds.y),
        fontSize,
        color
    );
}

void Label::setText(const std::string& newText)
{
    text = newText;
    preferredBounds.width = static_cast<float>(MeasureText(text.c_str(), fontSize));
}

const std::string& Label::GetText() const
{
    return text;
}
