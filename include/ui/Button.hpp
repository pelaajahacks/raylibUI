#pragma once

#include "Label.hpp"
#include "raygui.h"

#include <functional>
#include <string>
class Button : public Label {
  public:
    Button(const std::string& text);

    void update() override {}
    void draw() override;

    bool isClicked() const;
    void setOnClick(std::function<void()> onClick);

  private:
    bool clicked = false;
    std::function<void()> onClick;
};
