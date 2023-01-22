#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SCRL, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

#ifdef RGB_MATRIX_ENABLE
/**
    [RGB] = LAYOUT(
        ESC: 0,    1: 1,      2: 2,      3: 3,    4: 4,    5: 5,    6: 6,    7: 7,    8: 8,      9: 9,      0: 10,      MINS: 11,   EQL: 12,   BSPC: 13,  DEL: 14,
        TAB: 15,   Q: 16,     W: 17,     E: 18,   R: 19,   T: 20,   Y: 21,   U: 22,   I: 23,     O: 24,     P: 25,      LBRC: 26,   RBRC: 27,  BSLS: 28,  HOME: 29,
        CAPS: 30,  A: 31,     S: 32,     D: 33,   F: 34,   G: 35,   H: 36,   J: 37,   K: 38,     L: 39,     SCLN: 40,   QUOT: 41,              ENT: 42,   PGUP: 43,
        LSFT: 44,  Z: 45,     X: 46,     C: 47,   V: 48,   B: 49,   N: 50,   M: 51,   COMM: 52,  DOT: 53,   SLSH: 54,   RSFT: 55,              UP: 56,    PGDN: 57,
        LCTL: 58,  LGUI: 59,  LALT: 60,                    SPC: 61,                              RALT: 62,  FN: 63,                  LEFT: 64, DOWN: 65,  RGHT: 66
        //UnderGlow
        :67, :68, :69, :70, :71, :72, :73, :74, :75, :76, :77, :78, :79, :80, :81,
        :82, :83, :84, :85,
        :86, :87, :88, :89,
        :90, :91, :92, :93, :94, :95, :96, :97, :98, :99, :100, :101, :102, :103, :104, :105,
    ),
    [MATRIX] = LAYOUT(
        0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,         12,     13,     14,
        15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,         27,     28,     29,
        30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,         42,             43,
        44,     45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,                 56,     57,
        58,     59,     60,                             61,                         62,     63,         64,     65,     66,
        //UnderGlow
        90,     91,     92,     93,     94,     95,     96,     97,     98,     99,     100,    101,    102,    103,        104,        105,
        88,                                                                                                                             89,
        86,                                                                                                                             87,
        84,                                                                                                                             85,
        67,     68,     69,     70,     71,     72,     73,     74,     75,     76,     77,     78,     79,     80,     81,     82,     83
    ),
*/
#define LED_CAPS 30
#define LED_UNDERGLOW_START  67
#define LED_UNDERGLOW_STOP  105

static void rgb_matrix_set_color_underglow_all (uint8_t r, uint8_t g, uint8_t b) {
    uint8_t i = 0;

    for (i = LED_UNDERGLOW_START; i <= LED_UNDERGLOW_STOP; i++) {
        rgb_matrix_set_color (i, r, g, b);
    }
}

bool rgb_matrix_indicators_user (void) {
    // Make it so the caps LED toggles.
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPS, RGB_RED);
        rgb_matrix_set_color_underglow_all (RGB_RED);
    }
    else {
        rgb_matrix_set_color(LED_CAPS, RGB_OFF);
        rgb_matrix_set_color_underglow_all (RGB_WHITE);
    }
    return false;
}

#endif // RGB_MATRIX_ENABLE
