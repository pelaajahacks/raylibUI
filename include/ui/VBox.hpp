#pragma once

#include "FlexBox.hpp"

class VBox : public FlexBox {
public:
    explicit VBox(FlexConfig config = {})
        : FlexBox(FlexDirection::Column, config)
    {
    }
};
