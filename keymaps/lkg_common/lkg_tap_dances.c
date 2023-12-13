#include "lkg_km_common.h"

#include "lkg_tap_dances.h"

static tap dance_state[5];

uint8_t dance_step(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return TAP_THEN_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}


void dance_0_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LSFT)); break;
  case SINGLE_HOLD: register_code16(KC_LSFT); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
  case TAP_THEN_HOLD: layer_on(_NAVI); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_LSFT); register_code16(KC_LSFT); break;
  case MORE_TAPS: break;
  }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[0].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: clear_oneshot_mods(); unregister_code16(KC_LSFT); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSFT); break;
  }
  dance_state[0].step = 0;
}


void dance_1_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_RSFT)); break;
  case SINGLE_HOLD: register_code16(KC_RSFT); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
  case TAP_THEN_HOLD: layer_on(_NAVI); break; 
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RSFT); register_code16(KC_RSFT); break;
  case MORE_TAPS: break;
  }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[1].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: unregister_code16(KC_RSFT); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSFT); break;
  case MORE_TAPS: break;
  }
  dance_state[1].step = 0;
}


void dance_2_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[1].step) {
  case SINGLE_TAP: register_code16(KC_BTN2); break;
  case SINGLE_HOLD: register_code16(KC_BTN3); break;
  case DOUBLE_TAP:  break;
  case TAP_THEN_HOLD:  break; 
  case DOUBLE_SINGLE_TAP: tap_code16(KC_BTN2); register_code16(KC_BTN2); break;
  case MORE_TAPS: break;
  }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[2].step) {
  case SINGLE_TAP: unregister_code16(KC_BTN2); break;
  case SINGLE_HOLD: unregister_code16(KC_BTN3); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_BTN2); break;
  case MORE_TAPS: break;
  }
  dance_state[2].step = 0;
}



void dance_3_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[1].step) {
  case SINGLE_TAP: register_code16(KC_VOLD); break;
  case SINGLE_HOLD: register_code16(KC_MUTE); break;
  case DOUBLE_TAP:  break;
  case TAP_THEN_HOLD:  break; 
  case DOUBLE_SINGLE_TAP: tap_code16(KC_VOLD); register_code16(KC_VOLD);
  case MORE_TAPS: break;
  }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[3].step) {
  case SINGLE_TAP: unregister_code16(KC_VOLD); break;
  case SINGLE_HOLD: unregister_code16(KC_MUTE); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_VOLD); break;
  case MORE_TAPS: break;
  }
  dance_state[3].step = 0;
}


void dance_4_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[4].step = dance_step(state);
  switch (dance_state[0].step) {
  case SINGLE_TAP: add_mods(MOD_BIT(KC_LCTL)); tap_code(KC_F1); break;
  case SINGLE_HOLD: break;
  case DOUBLE_TAP: add_mods(MOD_BIT(KC_LALT)); tap_code(KC_F1); break; 
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[4].step) {
  case SINGLE_TAP: unregister_mods(MOD_BIT(KC_LCTL)); break;
  case SINGLE_HOLD: ; break;
  case DOUBLE_TAP: unregister_mods(MOD_BIT(KC_LALT)); break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  }
  dance_state[4].step = 0;
}


tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
  [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
  [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
  [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_4_finished, dance_4_reset),
};
