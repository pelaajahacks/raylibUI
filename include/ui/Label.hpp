#pragma once

#include "UIElement.hpp"

#include <string>

namespace ui {

class Label : public UIElement {
  public:
    Label(const std::string& text, Color color = BLACK, int fontSize = 20);

    void update() override {}
    void draw() override;

    void setText(const std::string& text);
    const std::string& GetText() const;

  private:
    int fontSize;
    Color color;
  protected:
    std::string text;
};

} // namespace ui
