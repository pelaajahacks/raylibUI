#pragma once

#include "UIElement.hpp"
#include "layout.h"
#include <vector>

namespace ui {

class Layout {
  public:
    Layout();
    ~Layout();
    void calculate(UIElement& root);
  private:
    lay_context ctx;
    lay_id build(UIElement& element, lay_id parent);
    void applyFlex(lay_id id, const FlexConfig& flex);
    std::vector<std::pair<UIElement*, lay_id>> items;
};

} // namespace ui
