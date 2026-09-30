#include "Panel.hpp"

#include <cstdint>

namespace {

uint32_t crossAlignmentFlag(Alignment alignment, bool horizontalAxis)
{
    switch (alignment) {
    case Alignment::Start: return horizontalAxis ? LAY_LEFT : LAY_TOP;
    case Alignment::End:   return horizontalAxis ? LAY_RIGHT : LAY_BOTTOM;
    case Alignment::Center:
    default:               return 0;
    }
}

uint32_t justifyFlag(Alignment alignment)
{
    switch (alignment) {
    case Alignment::Center: return LAY_MIDDLE;
    case Alignment::End:    return LAY_END;
    case Alignment::Start:
    default:                return LAY_START;
    }
}

} // namespace

Panel::Panel(Layout layout, FlexLayout flexLayout)
    : UIElement({0, 0, 0, 0}, layout),
      flexLayout(flexLayout)
{
    lay_init_context(&ctx);
    lay_reserve_items_capacity(&ctx, 256);
}

void Panel::runLayout()
{
    const bool row = flexLayout.direction == FlexDirection::Row;

    lay_reset_context(&ctx);

    layoutId = lay_item(&ctx);

    lay_set_size_xy(
        &ctx,
        layoutId,
        static_cast<int>(bounds.width),
        static_cast<int>(bounds.height));

    uint32_t container = row ? LAY_ROW : LAY_COLUMN;

    const Alignment mainAxisAlignment = row
        ? flexLayout.horizontalAlignment
        : flexLayout.verticalAlignment;
    container |= justifyFlag(mainAxisAlignment);

    lay_set_contain(&ctx, layoutId, container);

    const size_t count = children.size();
    for (size_t i = 0; i < count; ++i)
        createChildLayout(*children[i], i, count);

    lay_run_context(&ctx);

    for (auto& child : children) {
        lay_vec4 r = lay_get_rect(&ctx, child->getLayoutId());

        Rectangle childBounds{
            static_cast<float>(r[0]) + bounds.x,
            static_cast<float>(r[1]) + bounds.y,
            static_cast<float>(r[2]),
            static_cast<float>(r[3])
        };

        child->setBounds(childBounds);
    }
}

void Panel::draw() {
    runLayout();

    if (drawBackground)
        GuiPanel(bounds, nullptr);

    for (auto& child : children)
        child->draw();
}

void Panel::update() {
    for (auto& child : children)
        child->update();
}

void Panel::createChildLayout(UIElement& child, size_t index, size_t count)
{
    const bool row = flexLayout.direction == FlexDirection::Row;

    lay_id id = lay_item(&ctx);
    child.setLayoutId(id);

    lay_insert(&ctx, layoutId, id);

    const Layout& layout = child.getLayout();

    const Rectangle preferred = child.getPreferredBounds();

    const int width = layout.width == SizeMode::Fixed
        ? static_cast<int>(layout.widthValue)
        : layout.width == SizeMode::FitContent
            ? static_cast<int>(preferred.width)
            : 0;
    const int height = layout.height == SizeMode::Fixed
        ? static_cast<int>(layout.heightValue)
        : layout.height == SizeMode::FitContent
            ? static_cast<int>(preferred.height)
            : 0;

    lay_set_size_xy(&ctx, id, width, height);

    uint32_t behave = 0;

    if (layout.width == SizeMode::Fill) behave |= LAY_HFILL;
    if (layout.height == SizeMode::Fill) behave |= LAY_VFILL;
    if (layout.flexGrow > 0.0f) behave |= row ? LAY_HFILL : LAY_VFILL;

    const bool horizontalCrossAxis = !row;
    const Alignment crossAlignment = row
        ? flexLayout.verticalAlignment
        : flexLayout.horizontalAlignment;
    behave |= crossAlignmentFlag(crossAlignment, horizontalCrossAxis);

    lay_set_behave(&ctx, id, behave);

    const lay_scalar padding = static_cast<lay_scalar>(flexLayout.padding);
    const lay_scalar spacing = static_cast<lay_scalar>(flexLayout.spacing);

    lay_scalar left, top, right, bottom;
    if (row) {
        left  = static_cast<lay_scalar>(layout.offsetX) + (index == 0 ? padding : 0);
        top   = static_cast<lay_scalar>(layout.offsetY) + padding;
        right = index + 1 == count ? padding : spacing;
        bottom = padding;
    } else {
        left   = static_cast<lay_scalar>(layout.offsetX) + padding;
        top    = static_cast<lay_scalar>(layout.offsetY) + (index == 0 ? padding : 0);
        right  = padding;
        bottom = index + 1 == count ? padding : spacing;
    }

    lay_set_margins_ltrb(&ctx, id, left, top, right, bottom);
}
