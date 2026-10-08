#pragma once

#include "UIElement.hpp"
#include <memory>
#include <vector>


class Panel : public UIElement {
public:
  Panel(LayoutConfig layoutConfig)
    : UIElement(layoutConfig) {};

  void update() override { for (auto& child : children) { child->update(); }};
  void draw() override { for (auto& child : children) { child->draw(); }};

  void add(std::unique_ptr<UIElement> child) { children.push_back(std::move(child)); };
};
