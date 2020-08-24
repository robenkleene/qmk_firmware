// Netable differences vs. the default firmware for the ErgoDox EZ:
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // Default
#define FCTN 1 // Function
#define FCT2 2 // Function 2
#define UTIL 3 // Util
#define NUMB 4 // Util

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Default
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `     |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |      |           |  =   |   Y  |   U  |   I  |   O  |   P  |  BS    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  '     |
 * |--------+------+------+------+------+------|      |           |  -   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   ?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | LCTRL| LALT | LGUI |  Fn  |                                       |  Fn  | RGUI | RALT | RCTRL|      |
 *   `----------------------------------'                                       `----------------------------------'
                                                --------.       ,-------------.
 *                                        | LGUI |  Fn  |       |  Fn  | RGUI |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space | RET  |------|       |------|  Ret   |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default

// Left Keyboard
KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,      KC_5,  KC_NO,
KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,  KC_NO,
KC_ESC,    KC_A,     KC_S,     KC_D,     KC_F,      KC_G,
KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,  KC_NO,
TG(NUMB),  KC_LCTL,  KC_LALT,  KC_LGUI,  MO(FCTN),

// Left Cluster
KC_LGUI,  MO(FCTN),
KC_HOME,
KC_SPC,   KC_ENT,    KC_END,

// Right Keyboard
KC_NO,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_NO,
KC_EQL,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
KC_H,      KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
KC_MINS,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
MO(FCTN),  KC_RGUI,  KC_RALT,  KC_LCTL,  KC_NO,

// Right Cluster
MO(FCTN),  KC_RGUI,
KC_PGUP,
KC_PGDN,   KC_ENT,   KC_SPC

    ),

/* Function
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   `    |   1  |   2  |   3  |   4  |   5  | BriU |           | VolU |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |  -   |  =   |  [   |  ]   |   \    |
 * |--------+------+------+------+------+------| BriD |           | VolD |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |  F10 | F11  |      |           |      | F12  | Play | VolD | VolU |      |       |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *w  | TNSY |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |  RW  | FF   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[FCTN] = LAYOUT_ergodox(

// Left Keyboard
KC_TRNS,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_TRNS,
KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,    KC_BRIU,
MO(UTIL),  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
KC_TRNS,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_BRID,
KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(FCT2),

// Left Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,

// Right Keyboard
KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_TRNS,
KC_VOLU,  KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_TRNS,
KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,
KC_VOLD,  KC_F12,   KC_MPLY,  KC_VOLD,  KC_VOLU,   KC_UP,    KC_TRNS,
MO(FCT2), KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT,

// Right Cluster
KC_MPRV,  KC_MNXT,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS

),

// Function 2
[FCT2] = LAYOUT_ergodox(

// Left Keyboard
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

// Left Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,

// Right Keyboard
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,   KC_PGUP,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_END,

// Right Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS

),


// Util
[UTIL] = LAYOUT_ergodox(

// Left Keyboard
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

// Left Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,

// Right Keyboard
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  RESET,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

// Right Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS

),

// Function 2
[NUMB] = LAYOUT_ergodox(

// Left Keyboard
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

// Left Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,

// Right Keyboard
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

// Right Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS

),

};

void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case UTIL:
      ergodox_led_all_on();
      break;
    case FCTN:
      ergodox_right_led_3_on();
      break;
    case NUMB:
      ergodox_right_led_3_on();
      break;
    case FCT2:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
