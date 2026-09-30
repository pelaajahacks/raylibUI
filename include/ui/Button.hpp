#pragma once

#include "UIElement.hpp"
#include "raygui.h"

#include <functional>
#include <string>
class Button : public UIElement {
  public:
    Button(const std::string& text);

    void update() override {}
    void draw() override;

    bool isClicked() const;
    void setOnClick(std::function<void()> onClick);

  private:
    std::string text;
    bool clicked = false;
    std::function<void()> onClick;
};
