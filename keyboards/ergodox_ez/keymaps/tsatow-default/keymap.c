#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE   0 // default layer
#define FUNCS  1 // functions
#define MOUSES 2 // mouse keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |   {  |           |  }   |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   -  |           |  +   |   Y  |   U  |   I  |   O  |   P  | BackSp |
 * |--------+------+------+------+------+------|   _  |           |  =   |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|   ~  |           |  "   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |   `  |           |  '   |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LAlt | LGui |                                       | Left | Down |  Up  | Right|~FUNCS|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | PgUp |       | PgDn | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 | Space| -/_  |------|       |------| RGui |Space |
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_HOME,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_MINS,
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_GRV,
        KC_TRNS,        KC_TRNS,      KC_TRNS,KC_LALT,KC_LGUI,
                                                      KC_HOME,KC_PGUP,
                                                              KC_LALT,
                                               KC_SPC,KC_MINS,KC_LALT,
        // right hand
             KC_END,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSLS,
             KC_EQL,      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSPC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_ENT,
             KC_QUOT,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                               KC_LEFT,   KC_DOWN,KC_UP,  KC_RIGHT,         MO(FUNCS),
             KC_LBRC,     KC_RBRC,
             KC_RALT,
             KC_RALT,KC_RGUI, KC_SPC
    ),
/* Keymap 1: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Pow   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   Ins  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |      |      |      |      |      |MOUSE |           |      |      |      |      |      |  F11 |   Del  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  | VolDn| VolUp| Mute |      |      |------|           |------| Home | PgUp |      |      |  F12 |  PrSc  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |           |      | End  | PgDn |      |      |      | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Reset|      |      | LAlt | LGui |                                       | Left | Down |  Up  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | PgUp |       | PgDn | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 | Space| -/_  |------|       |------| RGui |Space |
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FUNCTIONS
[FUNCS] = KEYMAP(
       // left hand
       KC_PWR, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TAB, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,TG(MOUSES),
       KC_LCTL,KC_VOLD,KC_VOLU,KC_MUTE,KC_TRNS,KC_TRNS,
       KC_LSFT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_LALT,
                                KC_SPC,KC_LGUI,KC_LALT,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_DELT,
       KC_F11,  KC_F12,  KC_TRNS,KC_TRNS, KC_TRNS, KC_UP,   KC_INS,
                KC_TRNS, KC_HOME,KC_PGUP, KC_LEFT, KC_RIGHT,KC_PSCR,
       KC_TRNS, KC_2,    KC_TRNS,KC_END,  KC_PGDN, KC_DOWN, KC_RSFT,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_RALT,
       KC_RALT, KC_RGUI, KC_SPC
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      | BASE |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolDn |VolUp | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MOUSES] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FUNCS)                // ~FUNCS - Momentary Layer 1 (Functions)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};