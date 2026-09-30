#pragma once

enum class SizeMode {
    Fixed,
    FitContent,
    Fill
};

enum class FlexDirection {
    Row,
    Column
};

enum class Alignment {
    Start,
    Center,
    End
};

struct Layout {
    SizeMode width = SizeMode::FitContent;
    SizeMode height = SizeMode::FitContent;

    float widthValue = 0.0f;
    float heightValue = 0.0f;

    float offsetX = 0.0f;
    float offsetY = 0.0f;

    float flexGrow = 0.0f;
    float flexShrink = 1.0f;
};

struct FlexLayout {
    FlexDirection direction = FlexDirection::Column;

    float padding = 0.0f;
    float spacing = 0.0f;

    Alignment horizontalAlignment = Alignment::Start;
    Alignment verticalAlignment = Alignment::Start;
};