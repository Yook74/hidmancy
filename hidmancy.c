#include <furi.h>
#include <gui/gui.h>

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

    furi_delay_ms(3000);

    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_record_close(RECORD_GUI);

    return 0;
}
