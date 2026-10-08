#include "Label.hpp"
#include "raylib.h"

namespace ui {

Label::Label(const std::string& text, Color color, int fontSize)
    : text(text),
      fontSize(fontSize),
      color(color) {
  layoutConfig.width = static_cast<float>(MeasureText(text.c_str(), fontSize));
  layoutConfig.height = static_cast<float>(fontSize);
}

void Label::draw() {
    DrawText(
        text.c_str(),
        static_cast<int>(rect.x),
        static_cast<int>(rect.y),
        fontSize,
        color
    );
}

void Label::setText(const std::string& newText) {
    text = newText;
}

const std::string& Label::GetText() const {
    return text;
}

} // namespace ui
