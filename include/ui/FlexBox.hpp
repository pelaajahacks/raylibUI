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
        FlexConfig config = {},
        LayoutConfig layout = {}
    )
        : Panel(layout),
          direction(direction),
          config(config)
    {}

    FlexDirection getDirection() const { return direction; }
    const FlexConfig& getFlex() const { return config; }

  protected:
    FlexDirection direction;
    FlexConfig config;
};
