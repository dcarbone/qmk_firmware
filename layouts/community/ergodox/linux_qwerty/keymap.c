/*
 * This is built out of frustration with OSX / Sierra caps lock delay.
 * Fake it till you make it!
 */

#include QMK_KEYBOARD_H

enum layer_names {
    BASE, // default layer
    SYMB, // symbols
    MDIA  // media keys
};

#define BLINK_BASE  150U // timer threshold for blinking on MDIA layer

typedef enum onoff_t {OFF, ON} onoff;

#define caps_led_on  ergodox_right_led_2_on
#define caps_led_off ergodox_right_led_2_off


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |   6  |           |   `  |   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   [  |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsL  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   "    |
 * |--------+------+------+------+------+------| ~L1  |           |  ~L1 |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Gui  | Alt  | Left | Right|                                       | Down | Up   | Alt |  Gui  | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | L1   |       | Alt  | Ctrl   ]
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Backsp| Del  |------|       |------|  Enter | Spc  |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,     KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,
        KC_CAPS,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    MO(SYMB),
        KC_LCTL,    KC_LGUI,  KC_LALT, KC_LEFT, KC_RGHT,
                                                         KC_TRNS, TG(SYMB),
                                                                  KC_HOME,
                                                KC_BSPC, KC_DEL,  KC_END,
        // right hand
        KC_GRV,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_RBRC,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                    KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        MO(SYMB),   KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              KC_DOWN, KC_UP,   KC_RALT, KC_RGUI, KC_RCTL,
        KC_RALT,    KC_RCTL,
        KC_PGUP,
        KC_PGDN,    KC_ENT,   KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   L0 |  L2  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
    [SYMB] = LAYOUT_ergodox(
       // left hand
       KC_GRV ,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               TG(SYMB),TG(MDIA),
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Media and tenkey
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  BOOTL |      | Mute | Vol- | Vol+ | F14  | F15  |           |      |      | NumLk|   /  |  *   |  -   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+-----+-------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |  .   | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  L1  |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    // MEDIA AND TENKEY
    [MDIA] = LAYOUT_ergodox(
       QK_BOOT, KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_F14,  KC_F15,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
                                                    TG(MDIA),KC_NO,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_NO,   KC_NO,   KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, KC_NO,
       KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
                KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,
       KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_NO,
                         KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_NO,
       KC_NO,   KC_NO,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

// keeping around for future reference
// #ifndef NO_FAKE_CAPS
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     static onoff caps_state = OFF;

//     switch (keycode) {
//         case KC_CAPS:
//             if (record->event.pressed) {
//                 if (caps_state == OFF) {
//                     caps_led_on();
//                     caps_state = ON;
//                 } else {
//                     caps_led_off();
//                     caps_state = OFF;
//                 }
//             }
//             break;
//         default:
//             if (keycode < KC_A || keycode > KC_Z) {
//                 // This isn't an alpha or a KC_CAPS, continue on as usual.
//                 return true;
//             }
//             if (record->event.pressed) {
//                 bool shifted = (caps_state == ON && get_mods() == 0);
//                 if (shifted) {
//                     register_code(KC_LSFT);
//                 }
//                 register_code(keycode);
//                 if (shifted) {
//                     unregister_code(KC_LSFT);
//                 }
//             } else {
//                 unregister_code(keycode);
//             }
//             break;
//     }
//     // If we get here, we've already handled the keypresses.
//     return false;
// }
// #endif

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    static onoff layer_led_state = OFF;
    static uint16_t dt = 0;
    static uint8_t oldlayer = 0;

    if (oldlayer != layer) {
        // Layer was just toggled.
        if (layer == BASE) {
            ergodox_right_led_1_off();
            layer_led_state = OFF;
        } else {
            ergodox_right_led_1_on();
            layer_led_state = ON;
        }
    } else if (layer >= MDIA) {
        // We need to do blinking.
        if (timer_elapsed(dt) > BLINK_BASE) {
            // toggle
            dt = timer_read();
            if (layer_led_state == OFF) {
                ergodox_right_led_1_on();
                layer_led_state = ON;
            } else {
                ergodox_right_led_1_off();
                layer_led_state = OFF;
            }
        }
    }
    oldlayer = layer;
}
