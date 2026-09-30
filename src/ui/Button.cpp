#include "Button.hpp"

Button::Button(const std::string& text)
  : text(text) {
  int textSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
  int padding = GuiGetStyle(DEFAULT, TEXT_PADDING);
  layoutConfig.width =
  static_cast<float>(MeasureText(text.c_str(), textSize) + 2 * padding);

  layoutConfig.height = 24.0f;
}

void Button::draw() {
  // Cleared here, not in update(), so isClicked() stays readable for the whole
  // frame after the press instead of being wiped before anything can see it.
  clicked = false;

  if (GuiButton(rect, text.c_str())) {
    clicked = true;

    if (onClick)
      onClick();
  }
}

bool Button::isClicked() const {
  return clicked;
}

void Button::setOnClick(std::function<void()> onClick) {
  this->onClick = std::move(onClick);
}
