#define LAY_IMPLEMENTATION
#include "Layout.hpp"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

namespace ui {

Layout::Layout() {
  lay_init_context(&ctx);
}

Layout::~Layout() {
  lay_destroy_context(&ctx);
}

void Layout::calculate(UIElement& root) {
  lay_reset_context(&ctx);
  items.clear();

  build(root, LAY_INVALID_ID);

  lay_run_context(&ctx);

  for (const auto& item : items) {
    UIElement* element = item.first;
    lay_vec4 r = lay_get_rect(&ctx, item.second);

    element->setRect({
      static_cast<float>(r[0]),
      static_cast<float>(r[1]),
      static_cast<float>(r[2]),
      static_cast<float>(r[3])
    });
  }
}

lay_id Layout::build(UIElement& element, lay_id parent) {
  lay_id id = lay_item(&ctx);

  if (parent != LAY_INVALID_ID)
      lay_insert(&ctx, parent, id);

  const auto& config = element.getLayout();

  lay_set_size_xy(
      &ctx,
      id,
      config.width,
      config.height
  );

  switch (config.mode) {
    case LayoutMode::None:
        lay_set_behave(&ctx, id, LAY_LEFT | LAY_TOP);
        break;

    case LayoutMode::Flex:
        applyFlex(id, config.flex);
        break;
  }
  items.emplace_back(&element, id);

  for (const auto& child : element.getChildren())
      build(*child, id);

  return id;
}

void Layout::applyFlex(lay_id id, const FlexConfig& flex) {
    uint32_t contain = LAY_COLUMN;

    switch (flex.justify) {
        case Justify::Start:
            contain |= LAY_START;
            break;
        case Justify::Center:
            contain |= LAY_CENTER;
            break;
        case Justify::End:
            contain |= LAY_END;
            break;
    }

    lay_set_contain(&ctx, id, contain);
}

} // namespace ui
