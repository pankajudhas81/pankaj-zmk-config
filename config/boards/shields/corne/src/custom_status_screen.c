// FilePath: config/boards/shields/corne/src/custom_status_screen.c

/*
 * Custom Corne peripheral display
 * Trishul logo with ZMK built-in widgets
 */

#include <stdbool.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/peripheral_status.h>
#include <lvgl.h>

/* ── Trishul — 24px wide x 32px tall ──
 *
 *        ##            centre prong
 *       ####
 *       ####
 *       ####
 *  ##   ####   ##      side prongs
 *  ##   ####   ##
 *  ###  ####  ###
 *   ### #### ###
 *    ## #### ##        curves inward
 *     # #### #
 *      ##########      merge
 *       ########
 *        ######
 *         ####         shaft
 *         ····
 *        ######        base
 *       ########
 *       ########
 */

static const uint8_t raw_trishul[4 * 24] = {
    /* Page 0 (rows 0-7): prong tips */
      0,112,240,192,128,  0,  0,  0,
      0,  0,254,255,255,254,  0,  0,
      0,  0,  0,128,192,240,112,  0,
    /* Page 1 (rows 8-15): prongs merge into shaft */
      0,  0,  0,  1,  3,  7, 14, 28,
     56,112,255,255,255,255,112, 56,
     28, 14,  7,  3,  1,  0,  0,  0,
    /* Page 2 (rows 16-23): shaft */
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,255,255,255,255,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
    /* Page 3 (rows 24-31): shaft + base */
      0,  0,  0,  0,  0,  0,  0,  0,
    192,224,255,255,255,255,224,192,
      0,  0,  0,  0,  0,  0,  0,  0,
};

#define T_WIDTH  24
#define T_HEIGHT 32
#define T_STRIDE 3  /* ceil(24 / 8) */

/* ── Convert page format to LVGL I1 bitmap ── */

static uint8_t img_buf[8 + T_STRIDE * T_HEIGHT];

static lv_image_dsc_t trishul_dsc = {
    .header = {
        .cf = LV_COLOR_FORMAT_I1,
        .w  = T_WIDTH,
        .h  = T_HEIGHT,
    },
    .data_size = sizeof(img_buf),
    .data      = img_buf,
};

static void render_trishul(void) {
    /* I1 palette: index 0 = white bg, index 1 = black fg */
    img_buf[0] = 0xFF; img_buf[1] = 0xFF;
    img_buf[2] = 0xFF; img_buf[3] = 0xFF;
    img_buf[4] = 0x00; img_buf[5] = 0x00;
    img_buf[6] = 0x00; img_buf[7] = 0xFF;

    uint8_t *pixels = img_buf + 8;
    memset(pixels, 0, T_STRIDE * T_HEIGHT);

    for (int page = 0; page < 4; page++) {
        for (int col = 0; col < T_WIDTH; col++) {
            uint8_t val =
                raw_trishul[page * T_WIDTH + col];
            for (int bit = 0; bit < 8; bit++) {
                if (val & (1 << bit)) {
                    int y = page * 8 + bit;
                    pixels[y * T_STRIDE + (col / 8)]
                        |= (0x80 >> (col % 8));
                }
            }
        }
    }
}

/*
 * Screen layout (nice!view 160x68)
 *
 * +-----------+-----------+----------+
 * | BT status |           | Battery  |
 * +-----------+ [Trishul] +----------+
 * |           |           |          |
 * +-----------+-----------+----------+
 */

static struct zmk_widget_battery_status batt_widget;
static struct zmk_widget_peripheral_status bt_widget;

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

    /* Trishul — centred */
    lv_obj_t *img = lv_image_create(screen);
    render_trishul();
    trishul_dsc.data      = img_buf;
    trishul_dsc.header.cf = LV_COLOR_FORMAT_I1;
    lv_image_set_src(img, &trishul_dsc);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

    /* Peripheral (BT) status — top left */
    zmk_widget_peripheral_status_init(
        &bt_widget, screen);
    lv_obj_align(
        zmk_widget_peripheral_status_obj(&bt_widget),
        LV_ALIGN_TOP_LEFT, 0, 0);

    /* Battery status — top right */
    zmk_widget_battery_status_init(
        &batt_widget, screen);
    lv_obj_align(
        zmk_widget_battery_status_obj(&batt_widget),
        LV_ALIGN_TOP_RIGHT, 0, 0);

    return screen;
}
