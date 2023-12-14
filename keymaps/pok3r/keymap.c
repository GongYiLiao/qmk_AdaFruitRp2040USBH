#include "lkg_km_common.h"

#include "lkg_tap_dances.h"

#include "lkg_combos.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*

  
             ,-----------------------------------------------------------.         
             |  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12|         
             `-----------------------------------------------------------'         
	,----------------------------------------------------+-------------------.  
	|E/`~| LT3|  2@|  3#|  4$|  5%|  6^|  7&|  8*|  9(|  0)|  [{|  ]}|  Bspc |  
	|------+----+----+----+----+----+----+----+----+----+----+----+----+-----|  
	|   Tab| '" |  ,<|  .>|  P |  Y |  F |G/Pu| C/U|R/Pd|L/PS|//In|=/SL|     |  
	|--------+----+----+----+----+----+----+----+----+----+----+----+--------|  
	| Fn     |  A |  O |  E |  U |  I |D/Hm| H/L| T/D| N/R|  S |  -_|  Enter |                  
	|----------+----+----+----+----+----+----+----+----+----+----+-----------| 
	| TD0      |M/;:|  Q |  J |  K |  X |B/Ed|  M |  W |  V |  Z |   TD1     | 
	|-----+-----+-----+------------------------------+-----+-----+-----+-----| 
	| TD16| LG1 | TD18|                              |TD19 | Pn  | Fn  | TD17| 
	`------------------------------------------------------------------------'  

        TD0:   tap/hold: Left Shift, double-tap OSL(_EMACS_0), tap-then-held: TO(_NAVI) 
        TD1:   tap/hold: Right Shift, double-tap OSL(_EMACS_0), tap-then-held: TO(_NAVI)
	TD16:  tap: OSM(LCTL), held: LCTL;  tap-then-held: MO(NAVI)
        TD17:  tap: OSM(RCTL), held: RCTL;  tap-then-held: MO(NAVI)
        TD18:  tap: OSM(LALT), held: LALT;  tap-then-held: MO(NAVI)
	TD19:  tap: RALT,      held: LALT;  tap-then-held: MO(NAVI)
	LG1:   tap: menu key, held: GUI key
	LA1:   tap: right-alt, held: left-alt 
        CB0:   Q + J = OSL(_EMACS_0)
        CB1:   W + V = OSL(_EMACS_0)
   */
  [_DVORAK] = LAYOUT_pok3r(
			   KC_ESC,                                                                                                // ESC
			   KC_F1,                    KC_F2,           KC_F3,            KC_F4,        KC_F5,       KC_F6,         // F1 - F6
			   KC_F7,                    KC_F8,           KC_F9,            KC_F10,       KC_F11,      KC_F12,        // F7 - F12 
			   KC_PSCR,                  KC_SCRL,         KC_PAUS,                                                    // Print screen, scroll lock, Pause 
			   KC_GRV,                                                                                                // backquote 
			   KC_1,                     KC_2,            KC_3,             KC_4,         KC_5,                       // 1 - 5
			   KC_6,                     KC_7,            KC_8,             KC_9,         KC_0,                       // 6 - 0
			   KC_LBRC,                  KC_RBRC,                                                                     // -, + 
		           KC_BSPC,                                                                                               // Backspace 
			   KC_NO,                    KC_HOME,         KC_PGUP,                                                    // Insert, Home, PageUp
			   KC_TAB,                                                                                                // Tab
			   KC_QUOT,                  KC_COMM,         KC_DOT,           KC_P,         KC_Y,                       // Q - T
			   KC_F,                     KC_G,            KC_C,             KC_R,         KC_L,                       // Y - P
			   KC_SLSH,                  KC_EQL,                                                                      // [, ], 
			   KC_BSLS,                                                                                               // back slash
			   KC_DEL,                   KC_END,          KC_PGDN,                                                    // Del, End, PageDown
			   KC_NO,                                                                                                 // Capslock / Fn
			   KC_A,                     KC_O,            KC_E,             KC_U,         KC_I,                       // A - G
			   KC_D,                     KC_H,            KC_T,             KC_N,         KC_S,                       // D - semi-column
			   KC_MINS,                                                                                               // quote 
			   KC_ENT,                                                                                                // Enter 
			   TD(DANCE_0),                                                                                           // Left Shift
			   KC_SCLN,                  KC_Q,            KC_J,             KC_K,         KC_X,                       // Z - B
			   KC_B,                     KC_M,            KC_W,             KC_V,         KC_Z,                       // N - slash
			   TD(DANCE_1),                                                                                           // right shift, 
			   KC_UP,                                                                                                 // Up 
			   TD(DANCE_16),             LGUI_T(KC_APP),  TD(DANCE_18),                                               // Left Control, Left Super, Left Alt         
			   KC_SPC,                                                                                                // Spacebar 
			   TD(DANCE_19),             KC_APP,          TD(DANCE_17),                                               // Right Alt, Rigt Super, App (Menu), Right ctrl
			   KC_LEFT,                  KC_DOWN,         KC_RGHT                                                     // Left, Down, Right
			   ),

  /*
      
             ,-----------------------------------------------------------.   
             | F13| F14| F15| F16| F17| F18| F19| F20| F21| F22| F23| F24|   
             `-----------------------------------------------------------'   
	,------------------------------------------------------------------------. 
	| L0 | TD4| TD5| TD6| TD7| TD8| TD9|TD10|TD11|TD12|TD13|TD14|TD15|       | 
	|------+----+----+----+----+----+----+----+----+----+----+----+----+-----| 
	|      | V+ | TD2| MCU| MB1| MWU|    |    |    |    |    |    |    |     | 
	|--------+----+----+----+----+----+----+----+----+----+----+----+--------| 
	|        | MWL| MCL| MCD| MCR| MWR| MB1|    |    |    |    |    |        | 
	|----------+----+----+----+----+----+----+----+----+----+----+-----------| 
	|          | TD3| WBK| MSH| WFD| MWD|    |    |    |    |    |           | 
	|-----+-----+-----+------------------------------+-----+-----+-----+-----|           
	|     |     |     |                              |     |  Pn | Fn  |     |      
	`------------------------------------------------------------------------' 

        L0:  tap to _DVORAK
        TD2: tap: mouse button 2, held: mouse button 3
	TD3: tap: volume down, held mute 
        TD4: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD5: tap: F2, held: LCTL + F2, double-tap: LALT + F2, tap-then-held: LCTL+ALT+F2
        TD6: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD7: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD8: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD9: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD10: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD11: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD12: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD13: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD14: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
        TD15: tap: F1, held: LCTL + F1, double-tap: LALT + F1, tap-then-held: LCTL+ALT+F1
   */

  [_NAVI] = LAYOUT_pok3r(
			 TO(_DVORAK),                                                                                // ESC
			 KC_F13,       KC_F14,          KC_F15,           KC_F16,       KC_F17,       KC_F18,        // F1 - F6
			 KC_F19,       KC_F20,          KC_F21,           KC_F22,       KC_F23,       KC_F24,        // F7 - F12 
			 KC_NO,        KC_NO,           KC_NO,                                                       // Print screen, scroll lock, Pause 
			 KC_NO,                                                                                      // backquote 
			 TD(DANCE_4),  TD(DANCE_5),     TD(DANCE_6),      TD(DANCE_7),  TD(DANCE_8),                 // 1 - 5
			 TD(DANCE_9),  TD(DANCE_10),    TD(DANCE_11),     TD(DANCE_12), TD(DANCE_13),                // 6 - 0
			 TD(DANCE_14), TD(DANCE_15),                                                                 // -, + 
			 NK_ON,                                                                                      // Backspace 
			 KC_NO,        KC_NO,           KC_NO,                                                       // Insert, Home, PageUp
			 KC_NO,                                                                                      // Tab
			 KC_VOLU,      TD(DANCE_2),     KC_MS_U,          KC_BTN1,      KC_WH_U,                     // Q - T
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                       // Y - P
			 KC_NO,        KC_NO,                                                                        // [, ], 
			 KC_NO,                                                                                      // back slash
			 KC_NO,        KC_NO,           KC_NO,                                                       // Del, End, PageDown
			 KC_NO,                                                                                      // Capslock
			 KC_WH_L,      KC_MS_L,         KC_MS_D,          KC_MS_R,      KC_WH_R,                     // A - G
			 KC_BTN1,      KC_NO,           KC_NO,            KC_NO,        KC_NO,                       // D - semi-column
			 KC_NO,                                                                                      // quote 
			 KC_NO,                                                                                      // Enter 
			 KC_NO,                                                                                      // Left Shift
			 TD(DANCE_3),  KC_WBAK,         KC_WSCH,          KC_WFWD,      KC_WH_D,                     // Z - B
			 KC_NO,        KC_NO,           KC_NO,            KC_NO,        KC_NO,                       // N - slash
			 KC_NO,                                                                                      // right shift, 
			 KC_NO,                                                                                      // Up 
			 KC_NO,        KC_NO,           KC_NO,                                                       // Left Control, Left Super, Left Alt         
			 KC_NO,                                                                                      // Spacebar 
			 KC_NO,        KC_NO,           KC_NO,                                                       // Right Alt, App (Menu), Right control
			 KC_NO,        KC_NO,           KC_NO                                                        // Left, Down, Right
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
