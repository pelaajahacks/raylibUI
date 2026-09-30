#pragma once

#include "raylib.h"
#include "layout.h"

#include "layout.hpp"

class UIElement {
public:
    UIElement(Rectangle bounds, Layout layout)
        : bounds(bounds),
          preferredBounds(bounds),
          layout(layout) {}

    UIElement() = default;

    virtual ~UIElement() = default;

    virtual void draw() = 0;
    virtual void update() = 0;

    virtual Rectangle getBounds() const { return bounds; }

    virtual void setBounds(Rectangle bounds) { this->bounds = bounds; }

    virtual Rectangle getPreferredBounds() const { return preferredBounds; }

    virtual Layout getLayout() const { return layout; }

    lay_id getLayoutId() const { return layoutId; }
    void setLayoutId(lay_id id) { layoutId = id; }


protected:
    Rectangle bounds{};
    Rectangle preferredBounds{};
    Layout layout{};
    lay_id layoutId;
};
