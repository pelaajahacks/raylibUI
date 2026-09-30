#pragma once

#include "UIElement.hpp"
#include "layout.h"
#include <vector>

class Layout {
  public:
    Layout();
    ~Layout();
    void calculate(UIElement& root);
  private:
    lay_context ctx;
    lay_id build(UIElement& element, lay_id parent);
    std::vector<std::pair<UIElement*, lay_id>> items;
};
