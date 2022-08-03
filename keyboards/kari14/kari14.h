#pragma once

#include "quantum.h"
#include "./common/encoder_action.h"

/*
  ,-------------------.
  | e0r| e0l| e1r| e1l|
  `-------------------'
  ,-------------------.
  | 00 | 01 | 02 | na |
  |----+----+----+----|
  | 10 | 11 | 12 | na |
  |----+----+----+----|
  | 20 | 21 | 22 | 23 |
  |----+----+----+----|
  | 30 | 31 | 32 | 33 |
  `-------------------'
*/

#define LAYOUT( \
  e0r, e0l, e1r, e1l,\
  k00, k01, k02, k03,\
  k10, k11, k12, k13,\
  k20, k21, k22, k23,\
  k30, k31, k32, k33\
){ \
  {k00, k01, k02, k03},\
  {k10, k11, k12, k13},\
  {k20, k21, k22, k23},\
  {k30, k31, k32, k33},\
  {e0r, e0l, e1r, e1l},\
}

typedef union {
  uint32_t raw;
  struct {
    bool mac_mode :1;
    bool          :0;
    uint8_t encoder_resolutions[2];
  };
} user_config_t;

#ifdef ENCODER_ENABLE
enum kb_keycodes {
    // ENCADJ = KC_FN0,
    CHENCR0,
    CHENCR1,
    ENC_00,
    ENC_01,
    ENC_02,
    ENC_03,
    ENC_04,
    ENC_10,
    ENC_11,
    ENC_12,
    ENC_13,
    ENC_14,
    USR_SAFE_RANGE,
};
#else
enum kb_keycodes {
    USR_SAFE_RANGE = SAFE_RANGE,
};
#endif