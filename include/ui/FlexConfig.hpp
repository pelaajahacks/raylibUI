#pragma once

enum class Justify {
    Start,
    Center,
    End
};

enum class Align {
    Start,
    Center,
    End
};

struct FlexConfig {
    Justify justify = Justify::Start;
    Align align = Align::Start;
    float gap = 0.0f;
};
