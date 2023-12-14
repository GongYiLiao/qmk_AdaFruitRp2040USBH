#include "lkg_km_common.h"

#include "lkg_tap_dances.h"

static tap dance_state[20];

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


void on_dance_4(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F1);
    tap_code16(KC_F1);
    tap_code16(KC_F1);
  }
  if(state->count > 3) {
    tap_code16(KC_F1);
  }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[4].step = dance_step(state);
  switch (dance_state[4].step) {
  case SINGLE_TAP: register_code16(KC_F1); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F1)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F1)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F1))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
  }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[4].step) {
  case SINGLE_TAP: unregister_code16(KC_F1); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F1)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F1)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F1))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
  }
  dance_state[4].step = 0;
}

void on_dance_5(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F2);
    tap_code16(KC_F2);
    tap_code16(KC_F2);
  }
  if(state->count > 3) {
    tap_code16(KC_F2);
  }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[5].step = dance_step(state);
  switch (dance_state[5].step) {
  case SINGLE_TAP: register_code16(KC_F2); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F2)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F2)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F2))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
  }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[5].step) {
  case SINGLE_TAP: unregister_code16(KC_F2); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F2)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F2)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F2))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
  }
  dance_state[5].step = 0;
}


void on_dance_6(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F3);
    tap_code16(KC_F3);
    tap_code16(KC_F3);
  }
  if(state->count > 3) {
    tap_code16(KC_F3);
  }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[6].step = dance_step(state);
  switch (dance_state[6].step) {
  case SINGLE_TAP: register_code16(KC_F3); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F3)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F3)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F3))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
  }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[6].step) {
  case SINGLE_TAP: unregister_code16(KC_F3); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F3)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F3)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F3))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
  }
  dance_state[6].step = 0;
}




void on_dance_7(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F4);
    tap_code16(KC_F4);
    tap_code16(KC_F4);
  }
  if(state->count > 3) {
    tap_code16(KC_F4);
  }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[7].step = dance_step(state);
  switch (dance_state[7].step) {
  case SINGLE_TAP: register_code16(KC_F4); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F4)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F4))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
  }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[7].step) {
  case SINGLE_TAP: unregister_code16(KC_F4); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F4)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F4))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
  }
  dance_state[7].step = 0;
}

void on_dance_8(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F5);
    tap_code16(KC_F5);
    tap_code16(KC_F5);
  }
  if(state->count > 3) {
    tap_code16(KC_F5);
  }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[8].step = dance_step(state);
  switch (dance_state[8].step) {
  case SINGLE_TAP: register_code16(KC_F5); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F5)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F5)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F5))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
  }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[8].step) {
  case SINGLE_TAP: unregister_code16(KC_F5); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F5)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F5)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F5))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
  }
  dance_state[8].step = 0;
}


void on_dance_9(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F6);
    tap_code16(KC_F6);
    tap_code16(KC_F6);
  }
  if(state->count > 3) {
    tap_code16(KC_F6);
  }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[9].step = dance_step(state);
  switch (dance_state[9].step) {
  case SINGLE_TAP: register_code16(KC_F6); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F6)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F6)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F6))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
  }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[9].step) {
  case SINGLE_TAP: unregister_code16(KC_F6); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F6)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F6)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F6))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
  }
  dance_state[9].step = 0;
}


void on_dance_10(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F7);
    tap_code16(KC_F7);
    tap_code16(KC_F7);
  }
  if(state->count > 3) {
    tap_code16(KC_F7);
  }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[10].step = dance_step(state);
  switch (dance_state[10].step) {
  case SINGLE_TAP: register_code16(KC_F7); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F7)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F7)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F7))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
  }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[10].step) {
  case SINGLE_TAP: unregister_code16(KC_F7); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F7)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F7)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F7))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
  }
  dance_state[10].step = 0;
}



void on_dance_11(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F8);
    tap_code16(KC_F8);
    tap_code16(KC_F8);
  }
  if(state->count > 3) {
    tap_code16(KC_F8);
  }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[11].step = dance_step(state);
  switch (dance_state[11].step) {
  case SINGLE_TAP: register_code16(KC_F8); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F8)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F8)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F8))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
  }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[11].step) {
  case SINGLE_TAP: unregister_code16(KC_F8); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F8)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F8)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F8))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
  }
  dance_state[11].step = 0;
}


void on_dance_12(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F9);
    tap_code16(KC_F9);
    tap_code16(KC_F9);
  }
  if(state->count > 3) {
    tap_code16(KC_F9);
  }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[12].step = dance_step(state);
  switch (dance_state[12].step) {
  case SINGLE_TAP: register_code16(KC_F9); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F9)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F9)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F9))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
  }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[12].step) {
  case SINGLE_TAP: unregister_code16(KC_F9); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F9)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F9)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F9))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
  }
  dance_state[12].step = 0;
}


void on_dance_13(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F10);
    tap_code16(KC_F10);
    tap_code16(KC_F10);
  }
  if(state->count > 3) {
    tap_code16(KC_F10);
  }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[13].step = dance_step(state);
  switch (dance_state[13].step) {
  case SINGLE_TAP: register_code16(KC_F10); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F10)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F10)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F10))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
  }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[13].step) {
  case SINGLE_TAP: unregister_code16(KC_F10); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F10)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F10)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F10))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
  }
  dance_state[13].step = 0;
}


void on_dance_14(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F11);
    tap_code16(KC_F11);
    tap_code16(KC_F11);
  }
  if(state->count > 3) {
    tap_code16(KC_F11);
  }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[14].step = dance_step(state);
  switch (dance_state[14].step) {
  case SINGLE_TAP: register_code16(KC_F11); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F11)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F11)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F11))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F11); register_code16(KC_F11);
  }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[14].step) {
  case SINGLE_TAP: unregister_code16(KC_F11); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F11)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F11)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F11))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F11); break;
  }
  dance_state[14].step = 0;
}


void on_dance_15(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_F12);
    tap_code16(KC_F12);
    tap_code16(KC_F12);
  }
  if(state->count > 3) {
    tap_code16(KC_F12);
  }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[15].step = dance_step(state);
  switch (dance_state[15].step) {
  case SINGLE_TAP: register_code16(KC_F12); break;
  case SINGLE_HOLD: register_code16(LCTL(KC_F12)); break;
  case DOUBLE_TAP: register_code16(LALT(KC_F12)); break;
  case TAP_THEN_HOLD: register_code16(LALT(LCTL(KC_F12))); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_F12); register_code16(KC_F12);
  }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[15].step) {
  case SINGLE_TAP: unregister_code16(KC_F12); break;
  case SINGLE_HOLD: unregister_code16(LCTL(KC_F12)); break;
  case DOUBLE_TAP: unregister_code16(LALT(KC_F12)); break;
  case TAP_THEN_HOLD: unregister_code16(LALT(LCTL(KC_F12))); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_F12); break;
  }
  dance_state[15].step = 0;
}



void dance_16_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[16].step = dance_step(state);
  switch (dance_state[16].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LCTL)); break;
  case SINGLE_HOLD: register_code16(KC_LCTL); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
  case TAP_THEN_HOLD: layer_on(_NAVI); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_LCTL); register_code16(KC_LCTL); break;
  case MORE_TAPS: break;
  }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[16].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: clear_oneshot_mods(); unregister_code16(KC_LCTL); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: layer_off(_NAVI); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCTL); break;
  }
  dance_state[16].step = 0;
}


void dance_17_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[17].step = dance_step(state);
  switch (dance_state[17].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_RCTL)); break;
  case SINGLE_HOLD: register_code16(KC_RCTL); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
  case TAP_THEN_HOLD: layer_on(_NAVI); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RCTL); register_code16(KC_RCTL); break;
  case MORE_TAPS: break;
  }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[17].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: clear_oneshot_mods(); unregister_code16(KC_RCTL); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: layer_off(_NAVI); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RCTL); break;
  }
  dance_state[17].step = 0;
}



void dance_18_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[18].step = dance_step(state);
  switch (dance_state[18].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LALT)); break;
  case SINGLE_HOLD: register_code16(KC_LALT); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
  case TAP_THEN_HOLD: layer_on(_NAVI); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_LALT); register_code16(KC_LALT); break;
  case MORE_TAPS: break;
  }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[18].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: clear_oneshot_mods(); unregister_code16(KC_LALT); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: layer_off(_NAVI); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_LALT); break;
  }
  dance_state[18].step = 0;
}




void on_dance_19(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_RALT);
    tap_code16(KC_RALT);
    tap_code16(KC_RALT);
  }
  if(state->count > 3) {
    tap_code16(KC_RALT);
  }
}


void dance_19_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[19].step = dance_step(state);
  switch (dance_state[19].step) {
  case SINGLE_TAP: register_code16(KC_RALT); break;
  case SINGLE_HOLD: register_code16(KC_LALT); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
  case TAP_THEN_HOLD: layer_on(_NAVI); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RALT); register_code16(KC_RALT); break;
  case MORE_TAPS: break;
  }
}

void dance_19_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[19].step) {
  case SINGLE_TAP: unregister_code16(KC_RALT); break;
  case SINGLE_HOLD: clear_oneshot_mods(); unregister_code16(KC_LALT); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: layer_off(_NAVI); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RALT); break;
  }
  dance_state[19].step = 0;
}



tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
  [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
  [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
  [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
  [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
  [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
  [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
  [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
  [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
  [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
  [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
  [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
  [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
  [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
  [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
  [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_16_finished, dance_16_reset),
  [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_17_finished, dance_17_reset),
  [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_18_finished, dance_18_reset),
  [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
};
