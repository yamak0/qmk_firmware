#include QMK_KEYBOARD_H
#include "keycode.h"
#include "kari14.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     ,-------------------.
     | e0r| e0l| e1r| e1l|
     `-------------------'
     ,-------------------.
     | 00 | 01 | 02 | nc |
     |----+----+----+----|
     | 10 | 11 | 12 | nc |
     |----+----+----+----|
     | 20 | 21 | 22 | 23 |
     |----+----+----+----|
     | 30 | 31 | 32 | 33 |
     `-------------------'
     */
    [_NUMPAD] = LAYOUT(
        KC_MS_WH_UP,   KC_MS_WH_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,
        LT(3,KC_PENT), LT(2,KC_PDOT), LT(1,KC_P0),     KC_NO,
        KC_P3,         KC_P2,         KC_P1,           KC_NO,
        KC_P6,         KC_P5,         KC_P4,           KC_PMNS,
        KC_P9,         KC_P8,         KC_P7,           KC_PPLS
    ),

    [_RAISE] = LAYOUT(
        KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_NO,
        KC_NUM_LOCK,    KC_NUM_LOCK,    KC_NUM_LOCK,     KC_NO,
        KC_NUM_LOCK,    KC_NUM_LOCK,    KC_NUM_LOCK,     KC_TRANSPARENT,
        KC_NUM_LOCK,    KC_NUM_LOCK,    KC_NUM_LOCK,     KC_TRANSPARENT
    ),

    [_LOWER] = LAYOUT(
        KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_NO,
        KC_BACKSPACE,   LSFT(KC_TAB),   KC_TAB,          KC_NO,
        KC_BACKSPACE,   LSFT(KC_TAB),   KC_TAB,          KC_TRANSPARENT,
        KC_BACKSPACE,   LSFT(KC_TAB),   KC_TAB,          KC_TRANSPARENT
    ),

    [_ADJUST] = LAYOUT(
        KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_NO,
        KC_BACKSPACE,   LSFT(KC_TAB),   KC_TAB,          KC_NO,
        KC_BACKSPACE,   LSFT(KC_TAB),   KC_TAB,          KC_TRANSPARENT,
        KC_BACKSPACE,   LSFT(KC_TAB),   KC_TAB,          KC_TRANSPARENT
    ),
};