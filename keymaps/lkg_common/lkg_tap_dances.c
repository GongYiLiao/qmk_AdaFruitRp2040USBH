#include "lkg_km_common.h"

#include "lkg_tap_dances.h"

static tap dance_state[4];

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
  case SINGLE_TAP: register_code16(KC_SPC); break;
  case SINGLE_HOLD: register_code16(KC_ENT); break;
  case DOUBLE_TAP: break; 
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[0].step) {
  case SINGLE_TAP: unregister_code16(KC_SPC); break;
  case SINGLE_HOLD: unregister_code16(KC_ENT); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  }
  dance_state[0].step = 0;
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
  case SINGLE_TAP: register_code16(KC_F3); break;
  case SINGLE_HOLD: register_code16(KC_WH_U); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break; 
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[1].step) {
  case SINGLE_TAP: unregister_code16(KC_F3); break;
  case SINGLE_HOLD: unregister_code16(KC_WH_U); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
  dance_state[1].step = 0;
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[2].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_RALT)); break;
  case SINGLE_HOLD: register_code16(KC_LALT); break;
  case DOUBLE_TAP:  break;
  case TAP_THEN_HOLD:  break; 
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RALT); register_code16(KC_RALT); break;
  case MORE_TAPS: break;
  }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[2].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: clear_oneshot_mods(); unregister_code16(KC_LALT); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RALT); break;
  case MORE_TAPS: break;
  }
  dance_state[2].step = 0;
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[3].step) {
  case SINGLE_TAP: register_code16(KC_RBRC); break;
  case SINGLE_HOLD: register_code16(KC_MS_BTN1); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {
  case SINGLE_TAP: unregister_code16(KC_RBRC); break;
  case SINGLE_HOLD: unregister_code16(KC_MS_BTN1); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
  dance_state[3].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
  [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
  [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
};
