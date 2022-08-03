// Copyright 2022 yamako (@yamako)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x9786
#define DEVICE_VER 0x0001
#define MANUFACTURER yamako
#define PRODUCT      kari14

#define MATRIX_ROWS 5
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS {GP26,GP13,GP12,GP11,NO_PIN}
#define MATRIX_COL_PINS {GP27,GP28,GP29,GP14}
#define UNUSED_PINS

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* encoders */
#define ENCODERS 2

#define ENCODERS_CCW_KEY { { 0, 4 },{ 2, 4 } }
#define ENCODERS_CW_KEY  { { 1, 4 },{ 3, 4 } }

#define ENCODERS_PAD_A {GP9, GP7}
#define ENCODERS_PAD_B {GP10,GP8}

#define ENCODER_RESOLUTIONS { 4, 4 }

// #define DEBOUNCE 5