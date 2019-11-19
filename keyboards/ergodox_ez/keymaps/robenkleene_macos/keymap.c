// Netable differences vs. the default firmware for the ErgoDox EZ:
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // Default
#define FCTN 1 // Function

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Default
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  =   |           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |  =   |   Y  |   U  |   I  |   O  |   P  |  BS    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   "    |
 * |--------+------+------+------+------+------|      |           |  -   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   ?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Fn  |   ~  |   \  | LALT | LGUI |                                       | RGUI | RALT |   {  |   }  | Fn   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
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
KC_ESC,    KC_1,    KC_2,     KC_3,     KC_4,     KC_5,  KC_EQL,
KC_TAB,    KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,  KC_NO,
KC_LCTL,   KC_A,    KC_S,     KC_D,     KC_F,     KC_G,
KC_LSFT,   KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,  KC_NO,
MO(FCTN),  KC_GRV,  KC_BSLS,  KC_LALT,  KC_LGUI,

// Left Cluster
KC_LGUI,  MO(FCTN),
KC_HOME,
KC_SPC,   KC_ENT,    KC_END,

// Right Keyboard
KC_EQL,   KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_MINS,
KC_EQL,   KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_BSPC,
KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
KC_MINS,  KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,  KC_RSFT,
KC_RGUI,  KC_RALT,  KC_LBRC,  KC_RBRC,  MO(FCTN),

// Right Cluster
MO(FCTN),  KC_RGUI,
KC_PGUP,
KC_PGDN,   KC_ENT,   KC_SPC

    ),

/* Function
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TNSY   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | BriU |           | VolU |  FF  | Mute |      |      |      |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Play |      |      |      |      |        |
 * |--------+------+------+------+------+------| BriD |           | VolD |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  RW  | PgUp | HOME |  UP  | END  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | PgDn | LEFT | DOWN |RIGHT |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[FCTN] = LAYOUT_ergodox(

// Left Keyboard
RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRIU,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRID,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
// Left Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,

// Right Keyboard
KC_TRNS,  KC_F6,    KC_F7,    KC_F8,     KC_F9,    KC_F10,   KC_EQL,
KC_VOLU,  KC_MNXT,  KC_MUTE,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_MPLY,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
KC_VOLD,  KC_MPRV,  KC_PGUP,  KC_HOME,   KC_UP,    KC_END,   KC_TRNS,
KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_TRNS,

// Right Cluster
KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS

),

};

const uint16_t PROGMEM fn_actions[] = {
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
    case FCTN:
      ergodox_right_led_1_on();
      break;
    default:
      // none
      break;
  }

};
