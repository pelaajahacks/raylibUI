#pragma once

#include "raygui.h"
#include "layout.h"

#include <memory>
#include <vector>

#include "UIElement.hpp"

class Panel : public UIElement {
public:
    Panel(Layout layout, FlexLayout flexLayout);

    template<typename T, typename... Args>
    T* add(Args&&... args) {
        auto child = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = child.get();

        children.push_back(std::move(child));

        return ptr;
    }

    void draw() override;
    void update() override;

    void setDrawBackground(bool draw) { drawBackground = draw; }

private:
    void createChildLayout(UIElement& child, size_t index, size_t count);
    void runLayout();

    lay_context ctx;
    lay_id layoutId;

    FlexLayout flexLayout;
    std::vector<std::unique_ptr<UIElement>> children;

    bool drawBackground = true;
};
