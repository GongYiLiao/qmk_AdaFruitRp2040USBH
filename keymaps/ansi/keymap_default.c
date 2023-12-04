// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  _DVORAK,
  _NAVI_0,
  _NAVI_1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // F13 - F16      
		     KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // F17 - F20
		     KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // F21 - F24
		     KC_ESC,                                                                                    // ESC
		     KC_F1,        KC_F2,           KC_F3,            KC_F4,        KC_F5,       KC_F6,         // F1 - F6
		     KC_F7,        KC_F8,           KC_F9,            KC_F10,       KC_F11,      KC_F12,        // F7 - F12 
		     KC_PSCR,      KC_SCRL,         KC_PAUS,                                                    // Print screen, scroll lock, Pause 
		     KC_NO,        KC_NO,           KC_NO,            KC_NO,                                    // Vol-, Vol+, Mute, Power
		     KC_HELP,                                                                                   // Help
		     KC_GRV,                                                                                    // backquote 
		     KC_1,         KC_2,            KC_3,             KC_4,         KC_5,                       // 1 - 5
		     KC_6,         KC_7,            KC_8,             KC_9,         KC_0,                       // 6 - 0
		     KC_LBRC,      KC_RBRC,                                                                     // -, + 
		     KC_INT3,                                                                                   // INT3 - not used unless JP 
		     KC_BSPC,                                                                                   // Backspace 
		     KC_INS,       LT(1, KC_HOME),  LT(1, KC_PGUP),                                              // Insert, Home, PageUp
		     KC_NUM,       KC_PSLS,         KC_PAST,          KC_PMNS,                                  // NumLock, NP /, NP *, NP - 
		     KC_NO,        KC_NO,                                                                       // Stop / Resume 
		     KC_TAB,                                                                                    // Tab
		     KC_QUOT,      KC_COMM,         KC_DOT,           KC_P,         KC_Y,                       // Q - T
		     KC_F,         KC_G,            KC_C,             KC_R,         KC_L,                       // Y - P
		     KC_SLSH,      KC_EQL,                                                                      // [, ], 
		     KC_BSLS,                                                                                   // back slash
		     KC_DEL,       KC_END,          KC_PGDN,                                                    // Del, End, PageDown
		     KC_P7,        KC_P8,           KC_P9,            KC_PPLS,                                  // NP 7 - 9, NP + 
		     KC_MENU,      KC_UNDO,                                                                     // Menu, Undo 
		     KC_CAPS,                                                                                   // Capslock
		     KC_A,         KC_O,            KC_E,             KC_U,         KC_I,                       // A - G
		     KC_D,         KC_H,            KC_T,             KC_N,         KC_S,                       // D - semi-column
		     KC_MINS,                                                                                   // quote 
		     KC_NUHS,                                                                                   // No-US back slash 
		     KC_ENT,                                                                                    // Enter 
		     KC_P4,        KC_P5,           KC_P6,            KC_PCMM,                                  // NP 4 - 6, NP ,
		     KC_SLCT,      KC_COPY,                                                                     // Select, Copy
		     KC_LSFT,                                                                                   // Left Shift
		     KC_NUBS,                                                                                   // No-Us backslash
		     KC_SCLN,      KC_Q,            KC_J,             KC_K,         KC_X,                       // Z - B
		     KC_B,         KC_M,            KC_W,             KC_V,         KC_Z,                       // N - slash
		     KC_INT1,                                                                                   // not used unless JP
		     KC_RSFT,                                                                                   // right shift, 
		     KC_UP,                                                                                     // Up 
		     KC_P1,        KC_P2,           KC_P3,            KC_PEQL,                                  // NP 1 -3, NP = 
		     KC_EXEC,      KC_PSTE,                                                                     // Exec, Paste 
		     KC_LCTL,      KC_LGUI,         KC_LALT,                                                    // Left Control, Left Super, Left Alt         
		     KC_INT5,      KC_LNG2,                                                                     // INT5, LNG2, unused unless JP
		     KC_SPC,                                                                                    // Spacebar 
		     KC_LNG1, KC_INT4, KC_INT2,                                                                 // LNG1, INT4, INT2 - unued unless JP
		     KC_RALT, KC_RGUI, KC_APP,  KC_RCTL,                                                        // Right Alt, Rigt Super, App (Menu), Right control
		     KC_LEFT, KC_DOWN, KC_RGHT,                                                                 // Left, Down, Right
		     KC_P0,   KC_PDOT, KC_PENT,                                                                 // NP 0, NP Dot, Np Enter 
		     KC_FIND, KC_CUT                                                                            // Find, Cut
		     ),
  [_NAVI_0] = LAYOUT(KC_NO,  KC_NO,  KC_NO,  KC_NO,                      // F13 - F16      
		     KC_NO,  KC_NO,  KC_NO,  KC_NO,                      // F17 - F20
		     KC_NO,  KC_NO,  KC_NO,  KC_NO,                      // F21 - F 24
		     KC_NO,                                                 // ESC
		     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     // F1 - F6
		     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,    // F7 - F12 
		     KC_NO, KC_NO, KC_NO,                              // Print screen, scroll lock, Pause 
		     KC_NO, KC_NO, KC_NO, KC_NO,                      // Vol-, Vol+, Mute, Power
		     KC_NO,                                                // Help
		     KC_NO,                                                 // backquote 
		     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               // 1 - 5
		     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               // 6 - 0
		     KC_NO, KC_NO,                                       // -, + 
		     KC_NO,                                                // INT3 - not used unless JP 
		     KC_NO,                                                // Backspace 
		     KC_NO,  KC_NO, KC_NO,                              // Insert, Home, PageUp
		     KC_NO,  KC_NO, KC_NO, KC_NO,                     // NumLock, NP /, NP *, NP - 
		     KC_NO, KC_NO,                                       // Stop / Resume 
		     KC_NO,                                                 // Tab
		     KC_NO, KC_MS_BTN2, KC_MS_U,  KC_MS_BTN1,    KC_WH_U,               // Q - T
		     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               // Y - P
		     KC_NO, KC_NO,                                        // [, ], 
		     KC_NO,                                                // back slash
		     KC_NO,  KC_NO,  KC_NO,                              // Del, End, PageDown
		     KC_NO,   KC_NO,   KC_NO,   KC_NO,                     // NP 7 - 9, NP + 
		     KC_NO, KC_NO,                                       // Menu, Undo 
		     KC_NO,                                                // Capslock
		     KC_WH_L,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_R,               // A - G
		     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               // D - semi-column
		     KC_NO,                                                // quote 
		     KC_NO,                                                // No-US back slash 
		     KC_NO,                                                 // Enter 
		     KC_NO,   KC_NO,   KC_NO,   KC_NO,                     // NP 4 - 6, NP ,
		     KC_NO, KC_NO,                                       // Select, Copy
		     KC_NO,                                                // Left Shift
		     KC_NO,                                                // No-Us backslash
		     KC_NO, KC_NO,    KC_NO,    KC_WH_D,    KC_NO,               // Z - B
		     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,               // N - slash
		     KC_NO,                                                // not used unless JP
		     KC_NO,                                                // right shift, 
		     KC_NO,                                                  // Up 
		     KC_NO,   KC_NO,   KC_NO,   KC_NO,                     // NP 1 -3, NP = 
		     KC_NO, KC_NO,                                       // Exec, Paste 
		     KC_NO, KC_NO, KC_NO,                              // Left Control, Left Super, Left Alt         
		     KC_NO, KC_NO,                                       // INT5, LNG2, unused unless JP
		     KC_NO,                                                 // Spacebar 
		     KC_NO, KC_NO, KC_NO,                              // LNG1, INT4, INT2 - unued unless JP
		     KC_NO, KC_NO, KC_NO,  KC_NO,                     // Right Alt, Rigt Super, App (Menu), Right control
		     KC_NO, KC_NO, KC_NO,                              // Left, Down, Right
		     KC_NO,   KC_NO, KC_NO,                              // NP 0, NP Dot, Np Enter 
		     KC_NO, KC_NO                                         // Find, Cut
		     ),
};
