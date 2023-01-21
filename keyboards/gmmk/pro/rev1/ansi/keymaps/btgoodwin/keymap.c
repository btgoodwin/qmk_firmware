/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    // [0] = LAYOUT(
    //     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    //     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
    //     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
    //     KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    // ),

    // [1] = LAYOUT(
    //     _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
    //     _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,            _______,
    //     _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    //     _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
    //     _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SP     // ),

    // This layout mirrors my macOS -friendly layout that I use on a drop ALT.
	[0] = LAYOUT(
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
           KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_HOME,
           KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
           KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
           KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

	[1] = LAYOUT(
           KC_TRNS, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, RGB_TOG,          KC_TRNS,
           KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_TRNS,          KC_END,
           KC_TRNS, KC_TRNS, RGB_VAI, KC_TRNS, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,          KC_VOLU,
           KC_TRNS, KC_TRNS, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_VOLD,
           KC_TRNS,          KC_TRNS, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_PGUP, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END)


};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#ifdef RGB_MATRIX_ENABLE

#define LED_CAPS             3

// Rotary encoder (HOME)
#define LED_ENCODER         72

// Left-side strip
#define LED_LEFT_01         67
#define LED_LEFT_02         70
#define LED_LEFT_03         73
#define LED_LEFT_04         76
#define LED_LEFT_05         80
#define LED_LEFT_06         83
#define LED_LEFT_07         87
#define LED_LEFT_08         91

// Right-side strip
#define LED_RIGHT_01        68
#define LED_RIGHT_02        71
#define LED_RIGHT_03        74
#define LED_RIGHT_04        77
#define LED_RIGHT_05        81
#define LED_RIGHT_06        84
#define LED_RIGHT_07        88
#define LED_RIGHT_08        92

bool rgb_matrix_indicators_user (void) {
    // Make it so the caps LED toggles.
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPS, RGB_RED);

        rgb_matrix_set_color(LED_LEFT_01, RGB_RED);
        rgb_matrix_set_color(LED_LEFT_02, RGB_RED);
        rgb_matrix_set_color(LED_LEFT_03, RGB_RED);
        rgb_matrix_set_color(LED_LEFT_04, RGB_RED);
        rgb_matrix_set_color(LED_LEFT_05, RGB_RED);
        rgb_matrix_set_color(LED_LEFT_06, RGB_RED);
        rgb_matrix_set_color(LED_LEFT_07, RGB_RED);
        rgb_matrix_set_color(LED_LEFT_08, RGB_RED);

        rgb_matrix_set_color(LED_RIGHT_01, RGB_RED);
        rgb_matrix_set_color(LED_RIGHT_02, RGB_RED);
        rgb_matrix_set_color(LED_RIGHT_03, RGB_RED);
        rgb_matrix_set_color(LED_RIGHT_04, RGB_RED);
        rgb_matrix_set_color(LED_RIGHT_05, RGB_RED);
        rgb_matrix_set_color(LED_RIGHT_06, RGB_RED);
        rgb_matrix_set_color(LED_RIGHT_07, RGB_RED);
        rgb_matrix_set_color(LED_RIGHT_08, RGB_RED);
    }
    else {
        rgb_matrix_set_color(LED_CAPS, RGB_OFF);

        rgb_matrix_set_color(LED_LEFT_01, RGB_WHITE);
        rgb_matrix_set_color(LED_LEFT_02, RGB_WHITE);
        rgb_matrix_set_color(LED_LEFT_03, RGB_WHITE);
        rgb_matrix_set_color(LED_LEFT_04, RGB_WHITE);
        rgb_matrix_set_color(LED_LEFT_05, RGB_WHITE);
        rgb_matrix_set_color(LED_LEFT_06, RGB_WHITE);
        rgb_matrix_set_color(LED_LEFT_07, RGB_WHITE);
        rgb_matrix_set_color(LED_LEFT_08, RGB_WHITE);

        rgb_matrix_set_color(LED_RIGHT_01, RGB_WHITE);
        rgb_matrix_set_color(LED_RIGHT_02, RGB_WHITE);
        rgb_matrix_set_color(LED_RIGHT_03, RGB_WHITE);
        rgb_matrix_set_color(LED_RIGHT_04, RGB_WHITE);
        rgb_matrix_set_color(LED_RIGHT_05, RGB_WHITE);
        rgb_matrix_set_color(LED_RIGHT_06, RGB_WHITE);
        rgb_matrix_set_color(LED_RIGHT_07, RGB_WHITE);
        rgb_matrix_set_color(LED_RIGHT_08, RGB_WHITE);
    }
    return false;
}

#endif // RGB_MATRIX_ENABLE
