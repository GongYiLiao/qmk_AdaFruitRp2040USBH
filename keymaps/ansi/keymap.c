// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  _DVORAK,
  _NAVI,
  _EMACS_0,
};


typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,   
  TAP_THEN_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};

uint8_t dance_step(tap_dance_state_t *state);

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

enum tap_dance_codes {
  DANCE_0,       // TD0:  hold: L-Shift; double-tap OSL(_EMACS_0) tap-then-hold: MO(_NAVI) 
  DANCE_1,       // TD1:  hold: R-Ctrl; double-tap OSL(_EMACS_0) tap-then-hold: MO(_NAVI)
  DANCE_2,       // TD2:  tap: mouse right click, hold: mouse middle click
  DANCE_3,       // TD3:  tap: decrease volume, hold: mute
};                                                                                                     

static tap dance_state[3];


void dance_0_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LSFT)); break;
  case SINGLE_HOLD: register_code16(KC_LSFT); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
  case TAP_THEN_HOLD: layer_on(_NAVI); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_LSFT); register_code16(KC_LSFT);
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
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RSFT); register_code16(KC_RSFT);
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
  case DOUBLE_SINGLE_TAP: tap_code16(KC_BTN2); register_code16(KC_BTN2);
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


tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
  [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
  [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_2_reset),
};


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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*

  
   ,----.  ,-------------------. ,-------------------. ,-------------------.  ,--------------.
   | Esc|  |  F1|  F2|  F3|  F4| |  F5|  F6|  F7|  F8| |  F9| F10| F11| F12|  | PS | SL | PA |
   `----'  `-------------------' '-------------------' `-------------------'  `--------------'
   ,----------------------------------------------------+-------------------. ,--------------. ,-------------------.
   |  `~|  1!|  2@|  3#|  4$|  5%|  6^|  7&|  8*|  9(|  0)|  [{|  ]}|  Bspc | | In | Hm | PU | |  Nl|  P/|  P*|  P-|
   |------+----+----+----+----+----+----+----+----+----+----+----+----+-----| |----+----+----| |----+----+----+----|
   |   Tab| '" |  ,<|  .>|  P |  Y |  F |  G |  C |  R |  L |  /?|  =+|  \| | | Dl | Ed | PD | |  P7|  P8|  P9|    |
   |--------+----+----+----+----+----+----+----+----+----+----+----+--------| `--------------' |----+----+----+  P+|
   |   MO1  |  A |  O |  E |  U |  I |  D |  H |  T |  N |  S |  -_|  Enter |                  |  P4|  P5|  P6|    |
   |----------+----+----+----+----+----+----+----+----+----+----+-----------|      ,----.      |----+----+----+----|
   |    TD1   |  ;:|  Q |  J |  K |  X |  B |  M |  W |  V |  Z |    TD2    |      | Up |      |  P1|  P2|  P3|    |
   |-----+-----+-----+------------------------------+-----+-----+-----+-----| ,----+----+----. +---------+----+  PE|          
   | LC  | LG  | LA  |                              | RA  | RG  | Mn  | RC  | | Lf | Dn |  Rt| |    P0   |  P.|    |     
   `------------------------------------------------------------------------' `--------------' `-------------------'

    LT1:  tap as =, pressed activate _NAVI 
    TD0:  tap/hold: Left Shift, double-tap OSL(_EMACS_0), tap-the-held: TO(_NAVI) 
    TD1:  tap/hold: Right Shift, double-tap OSL(_EMACS_0), tap-the-held: TO(_NAVI)
    CB0:  Q + J = OSL(_EMACS_0)
    CB1:  W + V = OSL(_EMACS_0)

   */
  [_DVORAK] = LAYOUT_ansi(
			  KC_ESC,                                                                                                // ESC
			  KC_F1,                    KC_F2,           KC_F3,            KC_F4,        KC_F5,       KC_F6,         // F1 - F6
			  KC_F7,                    KC_F8,           KC_F9,            KC_F10,       KC_F11,      KC_F12,        // F7 - F12 
			  KC_PSCR,                  KC_SCRL,         KC_PAUS,                                                    // Print screen, scroll lock, Pause 
			  KC_GRV,                                                                                                // backquote 
			  KC_1,                     KC_2,            KC_3,             KC_4,         KC_5,                       // 1 - 5
			  KC_6,                     KC_7,            KC_8,             KC_9,         KC_0,                       // 6 - 0
			  KC_LBRC,                  KC_RBRC,                                                                     // -, + 
		          KC_BSPC,                                                                                               // Backspace 
			  KC_INS,                   KC_HOME,         KC_PGUP,                                                    // Insert, Home, PageUp
			  KC_NUM,                   KC_PSLS,         KC_PAST,          KC_PMNS,                                  // NumLock, NP /, NP *, NP - 
			  KC_TAB ,                                                                                               // Tab
			  KC_QUOT,                  KC_COMM,         KC_DOT,           KC_P,         KC_Y,                       // Q - T
			  KC_F,                     KC_G,            KC_C,             KC_R,         KC_L,                       // Y - P
			  KC_SLSH,                  KC_EQL,                                                                      // [, ], 
			  KC_BSLS,                                                                                               // back slash
			  KC_DEL,                   KC_END,          KC_PGDN,                                                    // Del, End, PageDown
			  KC_P7,                    KC_P8,           KC_P9,            KC_PPLS,                                  // NP 7 - 9, NP + 
			  LT(_NAVI, KC_EQL),                                                                                     // Capslock
			  KC_A,                     KC_O,            KC_E,             KC_U,         KC_I,                       // A - G
			  KC_D,                     KC_H,            KC_T,             KC_N,         KC_S,                       // D - semi-column
			  KC_MINS,                                                                                               // quote 
			  KC_ENT,                                                                                                // Enter 
			  KC_P4,                    KC_P5,           KC_P6,                                                      // NP 4 - 6,
			  TD(DANCE_0),                                                                                           // Left Shift
			  KC_SCLN,                  KC_Q,            KC_J,             KC_K,         KC_X,                       // Z - B
			  KC_B,                     KC_M,            KC_W,             KC_V,         KC_Z,                       // N - slash
			  TD(DANCE_1),                                                                                           // right shift, 
			  KC_UP,                                                                                                 // Up 
			  KC_P1,                    KC_P2,           KC_P3,            KC_PENT,                                  // NP 1 -3, NP Enter
			  KC_LCTL,                  KC_LGUI,         KC_LALT,                                                    // Left Control, Left Super, Left Alt         
			  KC_SPC,                                                                                                // Spacebar 
			  KC_RALT,                  KC_RGUI,         KC_APP,           KC_RCTL,                                  // Right Alt, Rigt Super, App (Menu), Right control
			  KC_LEFT,                  KC_DOWN,         KC_RGHT,                                                    // Left, Down, Right
			  KC_P0,                    KC_PDOT                                                                      // NP 0, NP Dot 
			  ),

  /*
      
   ,----. ,-------------------. ,-------------------. ,-------------------.   ,--------------.
   |    | |    |    |    |    | |    |    |    |    | |    |    |    |    |   |    |    |    |
   `----' `-------------------' '-------------------' `-------------------'   `--------------'
   ,------------------------------------------------------------------------. ,--------------. ,-------------------.
   | TO1  |    |    |    |    |    |    |    |    |    |    |    |    |       | |    |    |    | |    |    |    |    |
   |------+----+----+----+----+----+----+----+----+----+----+----+----+-----| |----+----+----| |----+----+----+----|
   |      | V+ |MB23| MCU| MB1| MWU|    |    |    |    |    |    |    |     | |    |    |    | | MB1| MCU| MB2|    |
   |--------+----+----+----+----+----+----+----+----+----+----+----+--------| `--------------' |----+----+----+ WHU|
   |   LT1  | MWL| MCL| MCD| MCR| MWR|    |    |    |    |    |    |        |                  | MCL| MB3| MCR|    |
   |----------+----+----+----+----+----+----+----+----+----+----+-----------|      ,----.      |----+----+----+----|
   |          |V-/M| WBK| WSC| WFW| MWD|    |    |    |    |    |           |      |    |      | WHL| MCD| WHR|    |
   |-----+-----+-----+------------------------------+-----+-----+-----+-----| ,----+----+----. +---------+----+ WHD|          
   |     |     |     |                              |     |     |     |     | |    |    |    | |         |    |    |     
   `------------------------------------------------------------------------' `--------------' `-------------------'

   
   */

  [_NAVI] = LAYOUT_ansi(
			TO(_DVORAK),                                                                               // ESC
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F1 - F6
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F7 - F12 
			NK_ON,        KC_NO,           KC_NO,                                                      // Print screen, scroll lock, Pause 
			TO(_DVORAK),                                                                               // backquote 
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // 1 - 5
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // 6 - 0
			KC_NO,        KC_NO,                                                                       // -, + 
			KC_NO,                                                                                     // Backspace 
			KC_NO,        KC_NO,           KC_NO,                                                      // Insert, Home, PageUp
			KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // NumLock, NP /, NP *, NP - 
			KC_NO,                                                                                     // Tab
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // Q - T
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // Y - P
			KC_NO,        KC_NO,                                                                       // [, ], 
			KC_NO,                                                                                     // back slash
			KC_NO,        KC_NO,           KC_NO,                                                      // Del, End, PageDown
			KC_BTN1,      KC_MS_U,         KC_BTN2,          KC_WH_U,                                  // NP 7 - 9, NP + 
			KC_NO,                                                                                     // Capslock
			KC_BTN1,      KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // A - G
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // D - semi-column
			KC_NO,                                                                                     // quote 
			KC_NO,                                                                                     // Enter 
			KC_MS_L,      KC_BTN3,         KC_MS_R,                                                    // NP 4 - 6
			KC_NO,                                                                                     // Left Shift
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // Z - B
			KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // N - slash
			KC_NO,                                                                                     // right shift, 
			KC_NO,                                                                                     // Up 
			KC_WH_L,      KC_MS_D,         KC_WH_R,          KC_WH_D,                                  // NP 1 -3, NP Enter 
			KC_NO,        KC_NO,           KC_NO,                                                      // Left Control, Left Super, Left Alt         
			KC_NO,                                                                                     // Spacebar 
			KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // Right Alt, Rigt Super, App (Menu), Right control
			KC_NO,        KC_NO,           KC_NO,                                                      // Left, Down, Right
			KC_NO,        KC_NO                                                                        // NP 0, NP Dot 
			),
  /* 
 
   Keymap: layer 2 - Emacs keybindings 0
  
   ,----. ,-------------------. ,-------------------. ,-------------------.     ,--------------.
   |    | |    |    |    |    | |    |    |    |    | |    |    |    |    |	|    |    |    |
   `----' `-------------------' '-------------------' `-------------------'	`----+----+----|

   ,--------------------------------------------------------------------------. ,--------------. ,-------------------.
   | QM16 | QM5| QW6| QM7|QM11|QM17|QM13|    |    |QM25| QM4|    |    |  QM15 | |QM26|QM27|QM28| |    |    |    |    |
   |-------+----+----+----+----+----+----+----+----+----+----+----+----+------| |----+----+----| |----+----+----+----|
   |       |    |    |    |QM14|    | QM0|    |QM22|QM23|QM20| QM9|QM10|      | |QM29|QM30|QM31| |    |    |    |    | 
   |--------+----+----+----+----+----+----+----+----+----+----+----+----------| '----+----+----' |----+----+----+----|
   |        |    |    |    |QM19|QM24|QM12|    |QM21|    | QM1|    |          |                  |    |    |    |    |
   |---------+----+----+----+----+----+----+----+----+----+----+--------------|      ,----.      |----+----+----+----|
   |         |    |QM18|    | QM3|    | QM2|    | QM8|    |    |              |      |    |      |    |    |    |    |
   |-----+-----+-----+--------------------------------+-----+-----+-----+-----| ,----+----+----. +---------+----+    |          
   |     |     |     |                                |     |     |     |     | |    |    |    | |         |    |    |       
   `--------------------------------------------------------------------------' `--------------' `-------------------'


        QM0:   C-x C-f  open file 
	QM1:   C-x C-s  save fie  
        QM2:   C-x C-b  list buffers
	QM3:   C-x K enter kill current buffer without asking
	QM4:   C-x 0 close window
	QM5:   C-x 1 close other window
	QM6:   C-x 2 split frame into two windows, horizontally
	QM7:   C-x 3 split frame into two windows, vertically
	QM8:   C-x C-w write file
	QM9:   C-x { last paragraph
	QM10:  C-x } next paragraph
	QM11:  C-x 4 b select buffer in other window
	QM12:  C-x 4 d open dired in other window
	QM13:  C-x ^ grow window taller
	QM14:  C-x C-p mark page
	QM15:  C-x 5 0 close frame
	QM16:  C-x 5 1 close other frames
	QM17   C-x 5 2 create new frame
	QM18:  C-x C-q toggle read-only mode
	QM19:  C-x C-u uppercase region
	QM20:  C-x C-l lowercase region
	QM21:  C-x C-t transpose lines
	QM22:  C-c C-c execute code (ess or elpy)
	QM23:  C-x r s save to register
	QM24:  C-x r i insert from register
	QM25:  (_)
	QM26:  C-x r r copy rectangle to register
	QM27:  C-x r k kill rectangle
	QM28:  C-x r o open rectangle shifting right text 
	QM29:  C-x r t prefix each line with a string
	QM30:  C-x r c blank out rectangle 
	QM31:  C-x r y yank rectange 
   */									            
  [_EMACS_0] = LAYOUT_ansi(
			   KC_NO,                                                                                     // ESC
			   KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F1 - F6
			   KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F7 - F12 
			   KC_NO,        KC_NO,           KC_NO,                                                      // Print screen, scroll lock, Pause 
			   QK_MACRO_16,                                                                               // backquote 
			   QK_MACRO_5,   QK_MACRO_6,      QK_MACRO_7,       QK_MACRO_11,  QK_MACRO_17,                // 1 - 5
			   QK_MACRO_13,  KC_NO,           KC_NO,            QK_MACRO_25,  QK_MACRO_4,                 // 6 - 0
			   KC_NO,        KC_NO,                                                                       // -, + 
			   QK_MACRO_15,                                                                               // Backspace 
			   QK_MACRO_26,  QK_MACRO_27,     QK_MACRO_28,                                                // Insert, Home, PageUp
			   KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // NumLock, NP /, NP *, NP - 
			   KC_NO,                                                                                     // Tab
			   KC_NO,        KC_NO,           KC_NO,            QK_MACRO_14,  KC_NO,                      // Q - T
			   QK_MACRO_0,   KC_NO,           QK_MACRO_22,      QK_MACRO_23,  QK_MACRO_20,                // Y - P
			   QK_MACRO_9,   QK_MACRO_10,                                                                 // [, ], 
			   KC_NO,                                                                                     // back slash
			   QK_MACRO_29,  QK_MACRO_30,     QK_MACRO_31,                                                // Del, End, PageDown
			   KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // NP 7 - 9, NP + 
			   KC_NO,                                                                                     // Capslock
			   KC_NO,        KC_NO,           KC_NO,            QK_MACRO_19,  QK_MACRO_24,                // A - G
			   QK_MACRO_12,  KC_NO,           QK_MACRO_21,      KC_NO,        QK_MACRO_1,                 // D - semi-column
			   KC_NO,                                                                                     // quote 
			   KC_NO,                                                                                     // Enter 
			   KC_NO,        KC_NO,           KC_NO,                                                      // NP 4 - 6
			   KC_NO,                                                                                     // Left Shift
			   KC_NO,        QK_MACRO_18,     KC_NO,            QK_MACRO_3,   KC_NO,                      // Z - B
			   QK_MACRO_2,   KC_NO,           QK_MACRO_8,       KC_NO,        KC_NO,                      // N - slash
			   KC_NO,                                                                                     // right shift, 
			   KC_NO,                                                                                     // Up 
			   KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // NP 1 -3, NP Enter 
			   KC_NO,        KC_NO,           KC_NO,                                                      // Left Control, Left Super, Left Alt         
			   KC_NO,                                                                                     // Spacebar 
			   KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // Right Alt, Rigt Super, App (Menu), Right control
			   KC_NO,        KC_NO,           KC_NO,                                                      // Left, Down, Right
			   KC_NO,        KC_NO                                                                        // NP 0, NP Dot 
			   ), 

};



#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

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
