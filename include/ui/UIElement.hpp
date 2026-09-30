#pragma once
#include "raygui.h"
#include "LayoutConfig.hpp"
#include <vector>
#include <memory>

class UIElement {
  public:
    UIElement(LayoutConfig layoutConfig = {})
      : layoutConfig(layoutConfig) {
    }
    virtual ~UIElement() = default;
    virtual void update() {}
    virtual void draw() {}

    Rectangle getRect() const { return rect; }
    void setRect(Rectangle rect) { this->rect = rect; }
    LayoutConfig& getLayout() { return layoutConfig; }

    const std::vector<std::unique_ptr<UIElement>>& getChildren() const {
      return children;
    }

  protected:
    Rectangle rect{};
    LayoutConfig layoutConfig{};
    std::vector<std::unique_ptr<UIElement>> children;
};
