#pragma once

#include "FlexBox.hpp"

class VBox : public FlexBox {
public:
    explicit VBox(LayoutConfig layout = {})
        : FlexBox(FlexDirection::Column, {}, layout)
    {
    }
};
