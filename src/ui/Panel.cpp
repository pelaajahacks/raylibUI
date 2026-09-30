#define RAYGUI_IMPLEMENTATION
#include "Panel.hpp"

Panel::Panel(LayoutConfig layoutConfig)
  : UIElement(layoutConfig) {
}

void Panel::add(std::unique_ptr<UIElement> child) {
    children.push_back(std::move(child));
}


void Panel::update() {
    for (auto& child : children)
        child->update();
}

void Panel::draw() {
    for (auto& child : children)
        child->draw();
}
