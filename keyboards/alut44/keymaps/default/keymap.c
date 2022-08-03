/* Copyright 2021 yamako
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
#include "keycode.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
    * ,-----------------------------------------------------------.
    * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
    * |-----------------------------------------------------------|
    * | Tab |  A |  S |  D |  F |  G |  H |  J |  K |  L | Enter  |
    * |-----------------------------------------------------------|
    * | LSft  |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  /   |
    * |-----------------------------------------------------------|
    * | LCtl| LGui| LAlt|L2fn|  spc fn1  |L2fn| ←  | ↓  | ↑  | →  |
    * `-----------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
        CTL_T(KC_TAB), KC_A, KC_S, KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_T(KC_SLSH),
        KC_LCTL, KC_LGUI, KC_LALT, LT(_RAISE, KC_MHEN),LT(_LOWER, KC_SPC), LT(_RAISE, KC_HENK), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),

    /* Lower Layer
    * ,-----------------------------------------------------------.
    * | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |Del |
    * |-----------------------------------------------------------|
    * |LCtrl| F1 | F2 | F3 | F4 | F5 | -  | =  | [  | ]  |   \    |
    * |-----------------------------------------------------------|
    * |LShift | F6 | F7 | F8 | F9 |F10 |F11 |F12 | ;  | '  | /fn3 |
    * |-----------------------------------------------------------|
    * |LCtrl| LGui| LAlt|MHEN|   Space   |HENK|Home|PgDn|PgUp|End |
    * `-----------------------------------------------------------'
    */
    [_LOWER] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_LANG5,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLASH,
        KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SCLN, KC_QUOT, SFT_T(KC_SLSH),
        KC_LCTL, KC_LGUI, KC_LALT, LT(_ADJUST, KC_MHEN),LT(_ADJUST, KC_SPC), LT(_ADJUST, KC_HENK), KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

	/* Raise Layer
     * ,-----------------------------------------------------------.
     * | ~  | !  | @  | #  | $  | %  | ^  | &  | *  |  ( |  ) |Del |
     * |-----------------------------------------------------------|
     * | Caps| F1 | F2 | F3 | F4 | F5 | _  | +  | {  | }  | PIPE   |
     * |-----------------------------------------------------------|
     * | Lshift| F6 | F7 | F8 | F9 |F10 |F11 |F12 | :  | "  | ?fn3 |
     * |-----------------------------------------------------------|
     * | LCtl| LGui| LAlt|MHEN|   Space   |HENK|Home|PgDn|PgUp|End |
     * `-----------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        LSFT(KC_CAPS),KC_F1,KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_COLN, KC_DQUO, SFT_T(KC_QUES),
        KC_LCTL, KC_LGUI, KC_LALT, LT(_ADJUST, KC_MHEN),LT(_ADJUST, KC_SPC), LT(_ADJUST, KC_HENK), KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),


	/* Adjust Layer
     * ,-----------------------------------------------------------.
     * |    |    | ↑  |    |    |    |Mute|VolD|VolU|Stop|    |CAD |
     * |-----------------------------------------------------------|
     * |     | ←  | ↓  | →  |    |    | ←  | ↓  | ↑  | →  |       ||
     * |-----------------------------------------------------------|
     * |       |    |    |    |    |    |    |    |    |    |     ||
     * |-----------------------------------------------------------|
     * |     |     |     |    |          |    |    |    |    |RESET|
     * `-----------------------------------------------------------'
      */
    [_ADJUST] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MSTP, KC_TRNS, KC_TRNS, LALT(LCTL(KC_DEL)),
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
    ),
};