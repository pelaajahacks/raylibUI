#pragma once

#include "UIElement.hpp"

#include "raygui.h"

#include <string>

class Button : public UIElement {
public:
    Button(Layout layout, const std::string& text);

    void update() override;
    void draw() override;

    bool isClicked() const;

private:
    std::string text;

    bool hovered = false;
    bool clicked = false;
};
