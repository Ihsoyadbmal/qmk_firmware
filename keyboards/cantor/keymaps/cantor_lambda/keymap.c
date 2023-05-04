// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "quantum.h"

#define NOP1 KC_NO
#define NOP2 KC_NO
#define NOP3 KC_NO

#define CK_AU LALT_T(FR_U)
#define CK_SI LSFT_T(FR_I)
#define CK_CE LCTL_T(FR_E)

#define CK_CT LCTL_T(FR_T)
#define CK_SS LSFT_T(FR_S)
#define CK_AR LALT_T(FR_R)

#define TD_INT_EXC LT(0, KC_A)
#define TD_VIR_COM LT(0, KC_B)
#define TD_DOT_CLN LT(0, KC_C)
#define TD_QUO_DQO LT(0, KC_D)
#define TD_C_CED LT(0, KC_E)
#define TD_SLH_BSH LT(0, KC_F)

#define BASE  0
#define NUM   1
#define NAV   2

#define L_BASE TT(BASE)
#define L_NUM  TT(NUM)
#define L_NAV  TT(NAV)

enum custom_kc {
  FOO = SAFE_RANGE,
  BAR
};

enum combos {
  UNDO,
  REDO,
  AGRV,
  UGRV,
  ECUT,
  EGRV,
  LPRN,
  RPRN,
  LBRC,
  RBRC,
  LCBR,
  RCBR,
  LCHE,
  RCHE,
  UNDS,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM undo[] = {KC_TAB, FR_B, COMBO_END};
const uint16_t PROGMEM redo[] = {NOP2, FR_A, COMBO_END};
const uint16_t PROGMEM agrv[] = {FR_A, CK_AU, COMBO_END};
const uint16_t PROGMEM ugrv[] = {CK_AU, CK_SI, COMBO_END};
const uint16_t PROGMEM ecut[] = {CK_CE, CK_SI, COMBO_END};
const uint16_t PROGMEM egrv[] = {CK_CE, TD_QUO_DQO, COMBO_END};
const uint16_t PROGMEM lprn[] = {FR_W, FR_P, COMBO_END};
const uint16_t PROGMEM rprn[] = {FR_P, FR_O, COMBO_END};
const uint16_t PROGMEM lbrc[] = {FR_X, FR_Y, COMBO_END};
const uint16_t PROGMEM rbrc[] = {FR_Y, FR_K, COMBO_END};
const uint16_t PROGMEM lcbr[] = {FR_V, FR_D, COMBO_END};
const uint16_t PROGMEM rcbr[] = {FR_D, FR_L, COMBO_END};
const uint16_t PROGMEM lche[] = {FR_Q, FR_G, COMBO_END};
const uint16_t PROGMEM rche[] = {FR_G, FR_H, COMBO_END};
const uint16_t PROGMEM unds[] = {CK_CT, CK_SS, COMBO_END};

combo_t key_combos[] = {
  [UNDO] = COMBO(undo, C(FR_Z)),
  [REDO] = COMBO(redo, C(FR_Y)),
  [AGRV] = COMBO(agrv, FR_AGRV),
  [UGRV] = COMBO(ugrv, FR_UGRV),
  [ECUT] = COMBO(ecut, FR_EACU),
  [EGRV] = COMBO(egrv, FR_EGRV),
  [LPRN] = COMBO(lprn, FR_LPRN),
  [RPRN] = COMBO(rprn, FR_RPRN),
  [LBRC] = COMBO(lbrc, FR_LBRC),
  [RBRC] = COMBO(rbrc, FR_RBRC),
  [LCBR] = COMBO(lcbr, FR_LCBR),
  [RCBR] = COMBO(rcbr, FR_RCBR),
  [LCHE] = COMBO(lche, FR_LABK),
  [RCHE] = COMBO(rche, FR_RABK),
  [UNDS] = COMBO(rche, FR_UNDS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case LT(0, KC_A):
      if(record->tap.count && record->event.pressed) { // TAP
        tap_code16(FR_QUES);
      } else if (record->event.pressed) { // HOLD
        tap_code16(FR_EXLM);
      }
      return false;
    case LT(0, KC_B):
      if(record->tap.count && record->event.pressed) { // TAP
        tap_code16(FR_COMM);
      } else if (record->event.pressed) { // HOLD
        tap_code16(FR_SCLN);
      }
      return false;
    case LT(0, KC_C):
      if(record->tap.count && record->event.pressed) { // TAP
        tap_code16(FR_DOT);
      } else if (record->event.pressed) { // HOLD
        tap_code16(FR_COLN);
      }
      return false;
    case LT(0, KC_D):
      if(record->tap.count && record->event.pressed) { // TAP
        tap_code16(FR_QUOT);
      } else if (record->event.pressed) { // HOLD
        tap_code16(FR_DQUO);
      }
      return false;
    case LT(0, KC_E):
      if(record->tap.count && record->event.pressed) { // TAP
        tap_code16(FR_C);
      } else if (record->event.pressed) { // HOLD
        tap_code16(FR_CCED);
      }
      return false;
    case LT(0, KC_F):
      if(record->tap.count && record->event.pressed) { // TAP
        tap_code16(FR_SLSH);
      } else if (record->event.pressed) { // HOLD
        tap_code16(FR_BSLS);
      }
      return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  FR_B,    FR_W,     FR_P,    FR_O,    TD_VIR_COM,                         TD_DOT_CLN, FR_V,    FR_D,    FR_L,    FR_J,    KC_ESC,
        NOP2,    FR_A,    CK_AU,    CK_SI,   CK_CE,   TD_QUO_DQO,                         TD_C_CED,   CK_CT,   CK_SS,   CK_AR,   FR_N,    _______,
        _______, FR_Z,    FR_X,     FR_Y,    FR_K,    TD_INT_EXC,                         FR_M,       FR_Q,    FR_G,    FR_H,    FR_F,    _______,
                                             L_NAV,   KC_BSPC,    KC_DEL,         KC_ENT, KC_SPC,     L_NUM
    ),
    [NUM] = LAYOUT_split_3x6_3(
        _______, _______, FR_EQL,  TD_SLH_BSH, FR_MINS, FR_COMM,                          FR_DOT,  FR_PLUS, FR_ASTR, FR_CIRC, _______, _______,
        _______, FR_7,    FR_5,    FR_3,       FR_1,    FR_9,                             FR_8,    FR_0,    FR_2,    FR_4,    FR_6,    _______,
        _______, _______, _______, _______,    _______, FR_PIPE,                          FR_AMPR, _______, _______, _______, _______, _______,
                                               _______, _______, _______,        _______, _______, _______
    ),
    [NAV] = LAYOUT_split_3x6_3(
        _______, _______, FR_GRV,  FR_TILD, FR_AT,   FR_HASH,                         FR_DLR,  KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, FR_PERC,                         _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                         _______, KC_PGUP, _______, KC_PGDN, _______, _______,
                                            _______, _______, _______,       _______, _______, _______
    )
};
