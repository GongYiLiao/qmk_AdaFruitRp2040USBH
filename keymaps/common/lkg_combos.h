
enum combos {
  QJ_OSL_EMACS_0 = 0,
  WV_OSL_EMACS_0,
};

const uint16_t PROGMEM combo_0[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_W, KC_V, COMBO_END};

combo_t key_combos[] = {
  [QJ_OSL_EMACS_0] = COMBO(combo_0, OSL(_EMACS_0)),
  [WV_OSL_EMACS_0] = COMBO(combo_1, OSL(_EMACS_0)),
};
