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
  DOUBLE_HOLD,        // Actually tap then hold  
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
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}

static tap dance_state[2];

enum tap_dance_codes {
  DANCE_0,       // TD0:  hold: L-Shift; double-tap OSL(_EMACS_0) tap-then-hold: MO(_NAVI) 
  DANCE_1,       // TD1:  hold: R-Ctrl; double-tap OSL(_EMACS_0) tap-then-hold: MO(_NAVI) 
};                                                                                                     


void dance_0_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
  case SINGLE_TAP: register_code16(KC_LSFT); break;
  case SINGLE_HOLD: register_code16(KC_LSFT); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break; 
  case DOUBLE_HOLD: layer_on(_NAVI); break;
  case DOUBLE_SINGLE_TAP: tap_code16(KC_LSFT); register_code16(KC_LSFT);
  case MORE_TAPS: break;
  }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[0].step) {
  case SINGLE_TAP: unregister_code16(KC_LSFT); break;
  case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
  case DOUBLE_TAP: break;
  case DOUBLE_HOLD: layer_off(_NAVI); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSFT); break;
  }
  dance_state[0].step = 0;
}


void dance_1_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
  case SINGLE_TAP: register_code16(KC_RSFT); break;
  case SINGLE_HOLD: register_code16(KC_RSFT); break;
  case DOUBLE_TAP: set_oneshot_layer(_EMACS_0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
  case DOUBLE_HOLD: layer_on(_NAVI); break; 
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RSFT); register_code16(KC_RSFT);
  case MORE_TAPS: break;
  }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[1].step) {
  case SINGLE_TAP: unregister_code16(KC_RSFT); break;
  case SINGLE_HOLD: unregister_code16(KC_RSFT); break;
  case DOUBLE_TAP: break;
  case DOUBLE_HOLD: layer_off(_NAVI); break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSFT); break;
  case MORE_TAPS: break;
  }
  dance_state[1].step = 0;
}




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*

  
        ,-----------------------------------------------------------.         
        |  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12|         
        `-----------------------------------------------------------'         
	,----------------------------------------------------+-------------------.  
	|E/`~| LT3|  2@|  3#|  4$|  5%|  6^|  7&|  8*|  9(|  0)|  [{|  ]}|  Bspc |  
	|------+----+----+----+----+----+----+----+----+----+----+----+----+-----|  
	|   LT1| '" |  ,<|  .>|  P |  Y |  F |G/Pu| C/U|R/Pd|L/PS|//In|=/SL|  LT2|  
	|--------+----+----+----+----+----+----+----+----+----+----+----+--------|  
	| Fn     |  A |  O |  E |  U |  I |D/Hm| H/L| T/D| N/R|  S |  -_|  Enter |                  
	|-----+---------+----+----+----+----+----+----+----+----+----+-----------| 
	| LSht|  Menu/;:|  Q |  J |  K |  X |B/Ed|  M |  W |  V |  Z |   RSht    | 
	|-----+-----+-----+------------------------------+-----+-----+-----+-----| 
	| LC  | LG  | LA  |                              | RA  | Pn  | Fn  | RC  | 
	`------------------------------------------------------------------------'  

    LT1:  Pressed activate _EMACS_0, tap is tab
    LT2:  Pressed activate _EMCAS_0, tap is backslash, Fn + / => Pause
    LT3:  Pressed activate _NAVI, tap is 1/! 

   */
  [_DVORAK] = LAYOUT_pok3r(
			   KC_ESC,                                                                                                // ESC
			   KC_F1,                    KC_F2,           KC_F3,            KC_F4,        KC_F5,       KC_F6,         // F1 - F6
			   KC_F7,                    KC_F8,           KC_F9,            KC_F10,       KC_F11,      KC_F12,        // F7 - F12 
			   KC_PSCR,                  KC_SCRL,         KC_PAUS,                                                    // Print screen, scroll lock, Pause 
			   KC_GRV,                                                                                                // backquote 
			   LT(_NAVI, KC_1),          KC_2,            KC_3,             KC_4,         KC_5,                       // 1 - 5
			   KC_6,                     KC_7,            KC_8,             KC_9,         KC_0,                       // 6 - 0
			   KC_LBRC,                  KC_RBRC,                                                                     // -, + 
		           KC_BSPC,                                                                                               // Backspace 
			   KC_INS,                   KC_HOME,         KC_PGUP,                                                    // Insert, Home, PageUp
			   LT(_EMACS_0, KC_TAB),                                                                                  // Tab
			   KC_QUOT,                  KC_COMM,         KC_DOT,           KC_P,         KC_Y,                       // Q - T
			   KC_F,                     KC_G,            KC_C,             KC_R,         KC_L,                       // Y - P
			   KC_SLSH,                  KC_EQL,                                                                      // [, ], 
			   LT(_EMACS_0, KC_BSLS),                                                                                 // back slash
			   KC_DEL,                   KC_END,          KC_PGDN,                                                    // Del, End, PageDown
			   KC_NO,                                                                                                 // Capslock / Fn
			   KC_A,                     KC_O,            KC_E,             KC_U,         KC_I,                       // A - G
			   KC_D,                     KC_H,            KC_T,             KC_N,         KC_S,                       // D - semi-column
			   KC_MINS,                                                                                               // quote 
			   KC_ENT,                                                                                                // Enter 
			   KC_LSFT,                                                                                               // Left Shift
			   KC_SCLN,                  KC_Q,            KC_J,             KC_K,         KC_X,                       // Z - B
			   KC_B,                     KC_M,            KC_W,             KC_V,         KC_Z,                       // N - slash
			   KC_RSFT,                                                                                               // right shift, 
			   KC_UP,                                                                                                 // Up 
			   KC_LCTL,                  KC_LGUI,         KC_LALT,                                                    // Left Control, Left Super, Left Alt         
			   KC_SPC,                                                                                                // Spacebar 
			   KC_RALT,                  KC_APP,          KC_RCTL,                                                    // Right Alt, Rigt Super, App (Menu), Right ctrl
			   KC_LEFT,                  KC_DOWN,         KC_RGHT                                                     // Left, Down, Right
			   ),

  /*
      
        ,-----------------------------------------------------------.   
        |    |    |    |    |    |    |    |    |    |    |    |    |   
        `-----------------------------------------------------------'   
	,------------------------------------------------------------------------. 
	|    |    |    |    |    |    |    |    |    |    |    |    |    |       | 
	|------+----+----+----+----+----+----+----+----+----+----+----+----+-----| 
	|      |    |    |    |    |    | MWU| MB1| MCU| MB2|    |    |    |     | 
	|--------+----+----+----+----+----+----+----+----+----+----+----+--------| 
	|        | MB1|    |    |    |    | MWL| MBL| MB3| MCR| MWR|    |        | 
	|----------+----+----+----+----+----+----+----+----+----+----+-----------| 
	|          |    |    |    |    |    | MWD|    | MCD|    |    |           | 
	|-----+-----+-----+------------------------------+-----+-----+-----+-----|           
	|     |     |     |                              |     |  Pn | Fn  |     |      
	`------------------------------------------------------------------------' 

   
   */

  [_NAVI] = LAYOUT_pok3r(
			 KC_NO,                                                                                     // ESC
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F1 - F6
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F7 - F12 
			 KC_NO,        KC_NO,           KC_NO,                                                      // Print screen, scroll lock, Pause 
			 KC_NO,                                                                                     // backquote 
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // 1 - 5
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // 6 - 0
			 KC_NO,        KC_NO,                                                                       // -, + 
			 KC_NO,                                                                                     // Backspace 
			 KC_NO,        KC_NO,           KC_NO,                                                      // Insert, Home, PageUp
			 KC_NO,                                                                                     // Tab
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // Q - T
			 KC_WH_U,      KC_BTN1,         KC_MS_U,          KC_BTN2,      KC_NO,                      // Y - P
			 KC_NO,        KC_NO,                                                                       // [, ], 
			 KC_NO,                                                                                     // back slash
			 KC_NO,        KC_NO,           KC_NO,                                                      // Del, End, PageDown
			 KC_NO,                                                                                     // Capslock
			 KC_BTN1,      KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // A - G
			 KC_WH_L,      KC_MS_L,         KC_BTN3,          KC_MS_R,      KC_WH_R,                    // D - semi-column
			 KC_NO,                                                                                     // quote 
			 KC_NO,                                                                                     // Enter 
			 KC_NO,                                                                                     // Left Shift
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                      // Z - B
			 KC_WH_D,      KC_NO,           KC_MS_D,          KC_NO,        KC_NO,                      // N - slash
			 KC_NO,                                                                                     // right shift, 
			 KC_NO,                                                                                     // Up 
			 KC_NO,        KC_NO,           KC_NO,                                                      // Left Control, Left Super, Left Alt         
			 KC_NO,                                                                                     // Spacebar 
			 KC_NO,        KC_NO,           KC_NO,                                                      // Right Alt, App (Menu), Right control
			 KC_NO,        KC_NO,           KC_NO                                                       // Left, Down, Right
			 ),
  /* 
 
   Keymap: layer 2 - Emacs keybindings 0
  
          ,-----------------------------------------------------------. 
          |    |    |    |    |    |    |    |    |    |    |    |    |	
          `-----------------------------------------------------------'	
	  ,--------------------------------------------------------------------------. 
	  | QM16 | QM5| QW6| QM7|QM11|QM17|QM13|    |    |QM25| QM4|    |    |  QM15 | 
	  |-------+----+----+----+----+----+----+----+----+----+----+----+----+------| 
	  |       |QM26|QM27|QM28|QM14|    | QM0|    |QM22|QM23|QM20| QM9|QM10|      |  
	  |--------+----+----+----+----+----+----+----+----+----+----+----+----------| 
	  |        |QM29|QM30|QM31|QM19|QM24|QM12|    |QM21|    | QM1|    |          | 
	  |---------+----+----+----+----+----+----+----+----+----+----+--------------| 
	  |         |    |QM18|    | QM3|    | QM2|    | QM8|    |    |              | 
	  |-----+-----+-----+--------------------------------+-----+-----+-----+-----|           
	  |     |     |     |                                |     |     |     |     |        
	  `--------------------------------------------------------------------------' 


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
  [_EMACS_0] = LAYOUT_pok3r(
			    KC_NO,                                                                                     // ESC
			    KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F1 - F6
			    KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,       KC_NO,         // F7 - F12 
			    KC_NO,        KC_NO,           KC_NO,                                                      // Print screen, scroll lock, Pause 
			    QK_MACRO_16,                                                                               // backquote 
			    QK_MACRO_5,   QK_MACRO_6,      QK_MACRO_7,       QK_MACRO_11,  QK_MACRO_17,                // 1 - 5
			    QK_MACRO_13,  KC_NO,           KC_NO,            QK_MACRO_25,  QK_MACRO_4,                 // 6 - 0
			    KC_NO,        KC_NO,                                                                       // -, + 
			    QK_MACRO_15,                                                                               // Backspace 
			    KC_NO,        KC_NO,           KC_NO,                                                      // Insert, Home, PageUp
			    KC_NO,                                                                                     // Tab
			    QK_MACRO_26,  QK_MACRO_27,     QK_MACRO_28,      QK_MACRO_14,  KC_NO,                      // Q - T
			    QK_MACRO_0,   KC_NO,           QK_MACRO_22,      QK_MACRO_23,  QK_MACRO_20,                // Y - P
			    QK_MACRO_9,   QK_MACRO_10,                                                                 // [, ], 
			    KC_NO,                                                                                     // back slash
			    KC_NO,        KC_NO,           KC_NO,                                                      // Del, End, PageDown
			    KC_NO,                                                                                     // Capslock
			    QK_MACRO_29,  QK_MACRO_30,     QK_MACRO_31,      QK_MACRO_19,  QK_MACRO_24,                // A - G
			    QK_MACRO_12,  KC_NO,           QK_MACRO_21,      KC_NO,        QK_MACRO_1,                 // D - semi-column
			    KC_NO,                                                                                     // quote 
			    KC_NO,                                                                                     // Enter 
			    KC_NO,                                                                                     // Left Shift
			    KC_NO,        QK_MACRO_18,     KC_NO,            QK_MACRO_3,   KC_NO,                      // Z - B
			    QK_MACRO_2,   KC_NO,           QK_MACRO_8,       KC_NO,        KC_NO,                      // N - slash
			    KC_NO,                                                                                     // right shift, 
			    KC_NO,                                                                                     // Up 
			    KC_NO,        KC_NO,           KC_NO,                                                      // Left Control, Left Super, Left Alt         
			    KC_NO,                                                                                     // Spacebar 
			    KC_NO,        KC_NO,           KC_NO,                                                      // Right Alt, App (Menu), Right control
			    KC_NO,        KC_NO,           KC_NO                                                       // Left, Down, Right
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
