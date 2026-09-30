#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define LAYOUT_IMPLEMENTATION
#include <layout.h>

#include <ui/ui.hpp>

namespace ui {
    void init()
    {
        if (!IsWindowReady()) {
            TraceLog(LOG_WARNING, "ui::init(): called before the window is ready, ignoring.");
            TraceLog(LOG_WARNING, "ui::init(): GuiSetFont() silently drops a font with texture.id == 0, so raygui's scale factor stays 0.");
            TraceLog(LOG_WARNING, "ui::init(): call this after Game (InitWindow) is constructed.");
            return;
        }

        GuiSetFont(GetFontDefault());
    }
}
