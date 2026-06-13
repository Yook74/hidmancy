#include <furi.h>
#include <gui/gui.h>

#include "hid.h"

static void hidmancy_draw_callback(Canvas* canvas, void* context) {
    UNUSED(context);

    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 10, 20, "Beans!");
}

int32_t hidmancy_app(void* p) {
    UNUSED(p);

    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, hidmancy_draw_callback, NULL);

    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    configure_usb_as_hid();
    type_string("Beans");
    revert_usb_configuration();

    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_record_close(RECORD_GUI);

    return 0;
}
