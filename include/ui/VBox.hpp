#pragma once

#include "FlexBox.hpp"

namespace ui {

class VBox : public FlexBox {
public:
    explicit VBox(LayoutConfig layout = {})
        : FlexBox(FlexDirection::Column, {}, layout)
    {
    }
};

} // namespace ui
