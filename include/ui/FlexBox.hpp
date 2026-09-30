#pragma once

#include "Panel.hpp"
#include "FlexConfig.hpp"

enum class FlexDirection {
    Row,
    Column
};

class FlexBox : public Panel {
public:
    FlexBox(
        FlexDirection direction,
        FlexConfig config = {}
    );

    FlexDirection getDirection() const;
    const FlexConfig& getConfig() const;

protected:
    FlexDirection direction;
    FlexConfig config;
};
