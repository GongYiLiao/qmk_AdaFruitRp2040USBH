
enum combos {
  DOT_P_OSL_EMACS_0 = 0,
  G_C_OSL_EMACS_0,
  J_K_OSM_LCTL,
  M_W_OSM_RCTL,
  K_X_OSM_LALT,
  B_M_OSM_LALT,
  Q_J_K_OSL_NAVI,
  M_W_V_OSL_NAVI,  
};

const uint16_t PROGMEM combo_0[] = {KC_DOT, KC_P,          COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_G,   KC_C,          COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_J,   KC_K,          COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_M,   KC_W,          COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_K,   KC_X,          COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_B,   KC_M,          COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_Q,   KC_J,   KC_K,  COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_M,   KC_W,   KC_V,  COMBO_END};

combo_t key_combos[] = {
  [DOT_P_OSL_EMACS_0]  = COMBO(combo_0, OSL(_EMACS_0)),
  [G_C_OSL_EMACS_0]    = COMBO(combo_1, OSL(_EMACS_0)),
  [J_K_OSM_LCTL]       = COMBO(combo_2, OSM(MOD_LCTL)),
  [M_W_OSM_RCTL]       = COMBO(combo_3, OSM(MOD_RCTL)),
  [K_X_OSM_LALT]       = COMBO(combo_4, OSM(MOD_LALT)),
  [B_M_OSM_LALT]       = COMBO(combo_5, OSM(MOD_LALT)),  
  [Q_J_K_OSL_NAVI]     = COMBO(combo_6, OSL(_NAVI)),
  [M_W_V_OSL_NAVI]     = COMBO(combo_7, OSL(_NAVI)),  
};
