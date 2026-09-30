#include "Button.hpp"

Button::Button(Layout layout, const std::string& text)
    : UIElement({0, 0, 0, 0}, layout),
      text(text) {
    int textSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
    int padding = GuiGetStyle(DEFAULT, TEXT_PADDING);
    preferredBounds = {
        0.0f, 0.0f,
        static_cast<float>(MeasureText(text.c_str(), textSize) + 2 * padding) + 16.0f,
        24.0f
    };
}

void Button::update() {
    clicked = false;
}

void Button::draw() {
    if (GuiButton(bounds, text.c_str()))
        clicked = true;
}

bool Button::isClicked() const {
    return clicked;
}
