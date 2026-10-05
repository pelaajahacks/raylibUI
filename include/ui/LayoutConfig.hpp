#pragma once

#include <cstdint>
#include <raylib.h>

#include "FlexConfig.hpp"

enum class LayoutMode : uint8_t {
    None,
    Flex
};

struct Style {
  
    Color background = WHITE;
    Color textColor = BLACK;
};

struct LayoutConfig {
    float width = 200;
    float height = 200;
    
    LayoutMode mode = LayoutMode::Flex;
    FlexConfig flex;

};
