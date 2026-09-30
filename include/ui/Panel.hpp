#pragma once

#include "UIElement.hpp"
#include <memory>
#include <vector>

class Panel : public UIElement {
public:
  Panel(LayoutConfig layoutConfig);

  void update() override;
  void draw() override;

  void add(std::unique_ptr<UIElement> child);
};
