/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _BASE,
  _FCTN,
  _FCT2,
  _NUMB,
  _UTIL
};

#define FCTN MO(_FCTN)
#define FCT2 MO(_FCT2)
#define NUMB MO(_NUMB)
#define UTIL MO(_UTIL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,     KC_O,     KC_P,     KC_BSPC,
KC_ESC,     KC_A,     KC_S,     KC_D,     KC_F,  KC_G,    KC_H,    KC_J,  KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
TG(_FCTN),  KC_LCTL,  KC_LALT,  KC_LGUI,  FCTN,  KC_SPC,  KC_SPC,  FCTN,  KC_RGUI,  KC_RALT,  KC_RCTL,  KC_ENT
),

[_FCTN] = LAYOUT_planck_grid(
KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,     KC_7,     KC_8,       KC_9,     KC_0,     KC_TRNS,
UTIL,     KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_MINS,  KC_EQL,     KC_LBRC,  KC_RBRC,  KC_BSLS,
KC_TRNS,  KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,   KC_F12,   KC_MPLY,  KC_VOLD,    KC_VOLU,  KC_UP,    KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  FCT2,    KC_TRNS,  KC_TRNS,  FCT2,     TO(_NUMB),  KC_LEFT,  KC_DOWN,  KC_RIGHT
),

[_FCT2] = LAYOUT_planck_grid(
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_PGUP,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_END
),

[_NUMB] = LAYOUT_planck_grid(
KC_TRNS,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
TG(_NUMB),  KC_TRNS,  KC_TRNS,  KC_TRNS,  FCTN,     KC_TRNS,  KC_TRNS,  FCTN,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[_UTIL] = LAYOUT_planck_grid(
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

};

extern bool g_suspend_state;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case _BASE:
      rgb_matrix_set_color_all(17, 25, 17);
      break;
    case _FCTN:
      rgb_matrix_set_color_all(25, 0, 25);
      break;
    case _FCT2:
      rgb_matrix_set_color_all(0, 0, 25);
      break;
    case _NUMB:
      rgb_matrix_set_color_all(0, 25, 0);
      break;
    case _UTIL:
      rgb_matrix_set_color_all(25, 0, 0);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
