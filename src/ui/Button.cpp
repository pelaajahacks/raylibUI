#include "Button.hpp"

namespace ui {

Button::Button(const std::string& text)
  : Label(text) {
  // Size the box to the label instead of the other way around.
  // GuiGetTextWidth() measures with the same font, size and spacing that
  // GuiDrawText() renders with, and GuiButton() draws the text into
  // GetTextBounds(BUTTON, ...), which is bounds minus BORDER_WIDTH and
  // TEXT_PADDING on every side -- so those go back on, plus a margin so
  // glyphs never touch the frame.
  const int textSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
  const int border = GuiGetStyle(BUTTON, BORDER_WIDTH);
  const int padding = GuiGetStyle(BUTTON, TEXT_PADDING);
  const int margin = 8;

  const int width = GuiGetTextWidth(text.c_str()) + 2 * (border + padding + margin);
  const int height = textSize + 2 * (border + padding + margin);

  layoutConfig.width = static_cast<float>(width);
  layoutConfig.height = static_cast<float>(height);
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

} // namespace ui
