#include "grv/grv.h"
#include "grv_gfx/grv_window.h"
#include "grv_gfx/grv_bitmap_font.h"

int main(int argc, char** argv) {
    int window_width = 1920 / 4;
    int window_height = 1080 / 4;
    grv_window_t* w = grv_window_new(window_width, window_height, 2.0, grv_str_ref("grvbx"));
    grv_color_palette_init_with_type(&w->frame_buffer.palette, GRV_COLOR_PALETTE_PICO8);
    w->borderless = true;
    grv_window_show(w);

    while (true) {
        grv_window_poll_events();
        if (w->should_close) {
            break;
        }

        grv_frame_buffer_clear(&w->frame_buffer);
        grv_bitmap_font_t* font = NULL;
        grv_str_t text = grv_str_ref("grvbx");
        int str_width = grv_bitmap_font_calc_size(font, text).x;
        int x = (window_width - str_width) / 2;
        grv_put_text_u8(&w->frame_buffer, text, (vec2i){x, 2}, font, 7);
        grv_window_present(w);
        grv_str_free(&text);
        grv_sleep(1.0f/30.0f);
    }

    return 0;
}
