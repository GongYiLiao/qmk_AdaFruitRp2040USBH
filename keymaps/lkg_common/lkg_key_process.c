#include "lkg_km_common.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case QK_MACRO_0:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_F)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_1:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_S)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_2:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_B)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_3:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_K)SS_TAP(X_ENT));
      return false;
    case QK_MACRO_4:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_0));
      return false;
    case QK_MACRO_5:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_1));
      return false;
    case QK_MACRO_6:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_2));
      return false;
    case QK_MACRO_7:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_3));
      return false;
    case QK_MACRO_8:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_W)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_9:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_LBRC)SS_UP(X_LSFT));
      return false;
    case QK_MACRO_10:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_RBRC)SS_UP(X_LSFT));
      return false;
    case QK_MACRO_11:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_4)SS_TAP(X_B));
      return false;
    case QK_MACRO_12:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_4)SS_TAP(X_D));
      return false;
    case QK_MACRO_13:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_6)SS_UP(X_LSFT));
      return false;
    case QK_MACRO_14:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_P)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_15:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_5)SS_TAP(X_0));
      return false;
    case QK_MACRO_16:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_5)SS_TAP(X_1));
      return false;
    case QK_MACRO_17:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_5)SS_TAP(X_2));
      return false;
    case QK_MACRO_18:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_Q)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_19:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_U)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_20:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_L)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_21:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_T)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_22:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_C)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_C)SS_UP(X_LCTL));
      return false;
    case QK_MACRO_23:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_S));
      return false;
    case QK_MACRO_24:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_I));
      return false;
    case QK_MACRO_25:
      SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_9)SS_UP(X_LSFT)SS_DOWN(X_LSFT)SS_TAP(X_0)SS_UP(X_LSFT)SS_TAP(X_LEFT));
      return false;
    case QK_MACRO_26:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_R));
      return false;
    case QK_MACRO_27:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_K));
      return false;
    case QK_MACRO_28:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_O));
      return false;
    case QK_MACRO_29:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_T));
      return false;
    case QK_MACRO_30:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_C));
      return false;
    case QK_MACRO_31:
      SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_R)SS_TAP(X_Y));
      return false;
    }
  }

  return true;
};
