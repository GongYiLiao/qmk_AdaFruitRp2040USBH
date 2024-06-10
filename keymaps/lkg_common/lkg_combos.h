
enum combos {
  DOT_P_OSL_EMACS_0 = 0,
  G_C_OSL_EMACS_0,
  J_K_OSM_LCTL,
  M_W_OSM_RCTL,
  K_X_OSM_LALT,
  B_M_OSM_LALT,
  Q_J_OSM_LGUI,
  W_V_OSM_RGUI,
  Q_J_K_OSL_NAVI,
  M_W_V_OSL_NAVI,
  SCLN_X_MENU,
};

const uint16_t PROGMEM combo_0[] = {KC_DOT,    KC_P,          COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_G,      KC_C,          COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_J,      KC_K,          COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_M,      KC_W,          COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_K,      KC_X,          COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_B,      KC_M,          COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_Q,      KC_J,          COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_W,      KC_V,          COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_Q,      KC_J,   KC_K,  COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_M,      KC_W,   KC_V,  COMBO_END};
const uint16_t PROGMEM combo_10[] = {KC_SCLN,  KC_X,         COMBO_END};



combo_t key_combos[] = {
  [DOT_P_OSL_EMACS_0]  = COMBO(combo_0, OSL(_EMACS_0)),
  [G_C_OSL_EMACS_0]    = COMBO(combo_1, OSL(_EMACS_0)),
  [J_K_OSM_LCTL]       = COMBO(combo_2, OSM(MOD_LCTL)),
  [M_W_OSM_RCTL]       = COMBO(combo_3, OSM(MOD_RCTL)),
  [K_X_OSM_LALT]       = COMBO(combo_4, OSM(MOD_LALT)),
  [B_M_OSM_LALT]       = COMBO(combo_5, OSM(MOD_LALT)),  
  [Q_J_OSM_LGUI]       = COMBO(combo_6, OSM(MOD_LGUI)),
  [W_V_OSM_RGUI]       = COMBO(combo_7, OSM(MOD_RGUI)),  
  [Q_J_K_OSL_NAVI]     = COMBO(combo_8, OSL(_NAVI)),
  [M_W_V_OSL_NAVI]     = COMBO(combo_9, OSL(_NAVI)),
  [SCLN_X_MENU]        = COMBO(combo_10, KC_APP),
};
