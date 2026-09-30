#pragma once

#include "UIElement.hpp"

#include <string>

class Label : public UIElement
{
public:
    Label(Layout layout, const std::string& text, Color color = BLACK, int fontSize = 20);

    void update() override {};
    void draw() override;

    void setText(const std::string& text);
    const std::string& GetText() const;

private:
    std::string text;
    int fontSize;
    Color color;
};
