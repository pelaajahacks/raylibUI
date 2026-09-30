#define LAY_IMPLEMENTATION
#include "Layout.hpp"

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

  lay_set_size_xy(
    &ctx,
    id,
    element.getLayout().width,
    element.getLayout().height
  );

  // layout.h defaults to the free-layout model with centred attachment, so every
  // child of a parent gets the exact same centred rect -- they all overlap and
  // only the last one drawn is visible. Stack children top-to-bottom instead.
  lay_set_contain(&ctx, id, LAY_COLUMN | LAY_START);
  lay_set_behave(&ctx, id, LAY_LEFT | LAY_TOP);

  items.emplace_back(&element, id);

  for (const auto& child : element.getChildren())
    build(*child, id);

  return id;
}
