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
  _ARRW
};

#define FCTN MO(_FCTN)
#define ARRW TT(_ARRW)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,     KC_O,     KC_P,     KC_BSPC,
KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,  KC_G,    KC_H,    KC_J,  KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
ARRW,     KC_LCTL,  KC_LALT,  KC_LGUI,  FCTN,  KC_SPC,  KC_SPC,  FCTN,  KC_RGUI,  KC_RALT,  KC_RCTL,  KC_ENT
),

[_FCTN] = LAYOUT_planck_grid(
KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
KC_TRNS,  KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,   KC_F12,   KC_MPLY,  KC_HOME,  KC_TRNS,  KC_END,   KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[_ARRW] = LAYOUT_planck_grid(
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _FCTN:
            rgblight_setrgb (0x00,  0x00, 0xFF);
            break;
        case _ARRW:
            rgblight_setrgb (0xFF,  0x00, 0x00);
            break;
        default:
            rgblight_setrgb (0x00,  0xFF, 0xFF);
            break;
    }
    return state;
}
